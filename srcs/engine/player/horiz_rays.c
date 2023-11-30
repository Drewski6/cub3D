/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 09:02:47 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3D.h"
#include "math.h"

void	ft_horiz_looking_up(t_player *player,
						t_ray *h_ray, int bs, double arctan)
{
	h_ray->coord_y = player->coord.y / 30 * 30 + 30;
	h_ray->coord_x = (player->coord.y - h_ray->coord_y)
		* arctan + player->coord.x;
	h_ray->offset_y = bs;
	h_ray->offset_x = -h_ray->offset_y * arctan;
}


void	ft_horiz_looking_down(t_player *player,
						t_ray *h_ray, int bs, double arctan)
{
	h_ray->coord_y = player->coord.y / 30 * 30 + 0.0001;
	h_ray->coord_x = (player->coord.y - h_ray->coord_y)
		* arctan + player->coord.x;
	h_ray->offset_y = -bs;
	h_ray->offset_x = -h_ray->offset_y * arctan;
}

void	ft_horiz_looking_across(t_player *player, t_ray *h_ray)
{
	h_ray->coord_y = player->coord.y;
	if (h_ray->angle == 0)
		h_ray->coord_x = player->coord.x / 30 * 30 + 30;
	if (h_ray->angle == PI)
		h_ray->coord_x = player->coord.x / 30 * 30;
	h_ray->offset_y = 0;
	h_ray->offset_x = 30;
}

void	ft_horiz_dof(t_player *player, t_map_data *map_data, t_ray *h_ray,
				int max_dof)
{
	int	dof;
	int	map_x;
	int	map_y;

	dof = 0;
	while (dof < max_dof)
	{
		map_x = (h_ray->coord_x + 30) / 30;
		if (h_ray->angle > PI)
			map_y = (h_ray->coord_y) / 30;
		if (h_ray->angle < PI)
			map_y = (h_ray->coord_y + 30) / 30;
		if (map_y < 0 || map_x < 0
			|| map_y > map_data->size.y || map_x > map_data->size.x
			|| map_data->map[map_y][map_x] == '1')
		{
			h_ray->dist_from_player = ft_distance(player->coord.x,
					player->coord.y, h_ray->coord_x, h_ray->coord_y);
			return ;
		}
		h_ray->coord_y += h_ray->offset_y;
		h_ray->coord_x += h_ray->offset_x;
		dof += 1;
	}
}

void	ft_horiz_check(t_player *player, t_map_data *map_data, t_ray *h_ray,
				int max_dof)
{
	double	arctan;

	arctan = -1 / tan(h_ray->angle);
	if (arctan > 100)
		arctan = 100;
	if (arctan < -100)
		arctan = -100;
	if (h_ray->angle > PI)
		ft_horiz_looking_down(player, h_ray, map_data->map_block_size, arctan);
	if (h_ray->angle < PI)
		ft_horiz_looking_up(player, h_ray, map_data->map_block_size, arctan);
	if (h_ray->angle == 0 || h_ray->angle == PI)
		ft_horiz_looking_across(player, h_ray);
	ft_horiz_dof(player, map_data, h_ray, max_dof);
	return ;
}
