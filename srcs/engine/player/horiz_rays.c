/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:38:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 13:09:36 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3D.h"
#include "math.h"
#include <stdio.h>

/*
 *	***** ft_horiz_looking_up *****
 *
 *	DESCRIPTION:
 *		Check for when the player's angle is towards the top of the screen.
 *		Finds the ray coordinate (intersection coordinate with first gridline),
 *		then finds the offset (how much to add for each gridsquare).
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_horiz_looking_up(t_player *player,
						t_ray *h_ray, int bs, double arctan)
{
	h_ray->coord_y = player->coord.y / bs * bs + 0.0001;
	h_ray->coord_x = (player->coord.y - h_ray->coord_y)
		* arctan + player->coord.x;
	h_ray->offset_y = -bs;
	h_ray->offset_x = -h_ray->offset_y * arctan;
}

/*
 *	***** ft_horiz_looking_down *****
 *
 *	DESCRIPTION:
 *		Check for when the player's angle is towards the bottom of the screen.
 *		Finds the ray coordinate (intersection coordinate with first gridline),
 *		then finds the offset (how much to add for each gridsquare).
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_horiz_looking_down(t_player *player,
						t_ray *h_ray, int bs, double arctan)
{
	h_ray->coord_y = player->coord.y / bs * bs + bs;
	h_ray->coord_x = (player->coord.y - h_ray->coord_y)
		* arctan + player->coord.x;
	h_ray->offset_y = bs;
	h_ray->offset_x = -h_ray->offset_y * arctan;
}

/*
 *	***** ft_horiz_looking_across *****
 *
 *	DESCRIPTION:
 *		Performs check for when player is looking directly left or right.
 *		This is not common since we are using floats and the precision usually 
 *		prevents us from looking directly across so mostly this is an edgecase.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_horiz_looking_across(t_player *player, t_ray *h_ray, int bs)
{
	h_ray->coord_y = player->coord.y;
	if (h_ray->angle == 0)
		h_ray->coord_x = player->coord.x / bs * bs + bs;
	if (h_ray->angle == PI)
		h_ray->coord_x = player->coord.x / bs * bs;
	h_ray->offset_y = 0;
	h_ray->offset_x = bs;
}

/*
 *	***** ft_horiz_dof *****
 *
 *	DESCRIPTION:
 *		Uses the ray's offset values to increase the ray coordinates based on if a 
 *		wall is present in the grid block or not.
 *	RETURN:
 *		Function returns when a wall is encountered or loop meets 
 *		max depth of field.
 *		Void function does not return a value.
 */

void	ft_horiz_dof(t_player *player, t_map_data *map_data, t_ray *h_ray,
				int max_dof)
{
	int	dof;
	int	map_x;
	int	map_y;

	dof = 0;
	while (dof < max_dof)
	{
		map_x = (h_ray->coord_x + map_data->bs) / map_data->bs;
		if (h_ray->angle > PI)
			map_y = (h_ray->coord_y) / map_data->bs;
		if (h_ray->angle < PI)
			map_y = (h_ray->coord_y + map_data->bs) / map_data->bs;
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

/*
 *	***** ft_horiz_check *****
 *
 *	DESCRIPTION:
 *		Performs the checks for the horizontal intersections.
 *		First finds the intersection with the first gridline,
 *		then finds the offset (size of a grid square),
 *		then looks until a wall is seen.
 *	RETURN:
 *		Void function does not return a value.
 */

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
		ft_horiz_looking_up(player, h_ray, map_data->bs, arctan);
	if (h_ray->angle < PI)
		ft_horiz_looking_down(player, h_ray, map_data->bs, arctan);
	if (h_ray->angle == 0 || h_ray->angle == PI)
		ft_horiz_looking_across(player, h_ray, map_data->bs);
	ft_horiz_dof(player, map_data, h_ray, max_dof);
	return ;
}
