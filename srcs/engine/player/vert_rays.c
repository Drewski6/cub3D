/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:42:37 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 09:14:26 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3D.h"
#include "math.h"

/*
 *	***** ft_vert_looking_left *****
 *
 *	DESCRIPTION:
 *		Check for when the player's angle is towards the left of the screen.
 *		Finds the ray coordinate (intersection coordinate with first gridline),
 *		then finds the offset (how much to add for each gridsquare).
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_vert_looking_left(t_player *player,
						t_ray *v_ray, int bs, double negtan)
{
	v_ray->coord_x = player->coord.x / 30 * 30 + 0.0001;
	v_ray->coord_y = (player->coord.x - v_ray->coord_x)
		* negtan + player->coord.y;
	v_ray->offset_x = -bs;
	v_ray->offset_y = -v_ray->offset_x * negtan;
}

/*
 *	***** ft_vert_looking_right *****
 *
 *	DESCRIPTION:
 *		Check for when the player's angle is towards the right of the screen.
 *		Finds the ray coordinate (intersection coordinate with first gridline),
 *		then finds the offset (how much to add for each gridsquare).
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_vert_looking_right(t_player *player,
						t_ray *v_ray, int bs, double negtan)
{
	v_ray->coord_x = player->coord.x / 30 * 30 + 30;
	v_ray->coord_y = (player->coord.x - v_ray->coord_x)
		* negtan + player->coord.y;
	v_ray->offset_x = bs;
	v_ray->offset_y = -v_ray->offset_x * negtan;
}

/*
 *	***** ft_vert_looking_up_down *****
 *
 *	DESCRIPTION:
 *		Performs check for when player is looking directly up and down.
 *		This is not common since we are using floats and the precision usually 
 *		prevents us from looking directly up and down so mostly this is an edgecase.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_vert_looking_up_down(t_player *player, t_ray *v_ray)
{
	if (v_ray->angle == (PI / 2))
	{
		v_ray->coord_x = player->coord.x / 30 * 30 + 30;
		v_ray->coord_y = player->coord.y;
	}
	if (v_ray->angle == (3 * PI / 2))
	{
		v_ray->coord_x = player->coord.x;
		v_ray->coord_y = player->coord.y / 30 * 30;
	}
	v_ray->offset_x = 30;
	v_ray->offset_y = 0;
}

/*
 *	***** ft_vert_dof *****
 *
 *	DESCRIPTION:
 *		Uses the ray's offset values to increase the ray coordinates based on if a 
 *		wall is present in the grid block or not.
 *	RETURN:
 *		Function returns when a wall is encountered or loop meets 
 *		max depth of field.
 *		Void function does not return a value.
 */

void	ft_vert_dof(t_player *player, t_map_data *map_data, t_ray *v_ray,
				int max_dof)
{
	int	dof;
	int	map_x;
	int	map_y;

	dof = 0;
	while (dof < max_dof)
	{
		map_y = (v_ray->coord_y + 30) / 30;
		if (v_ray->angle > (PI / 2) && v_ray->angle < (3 * PI / 2))
			map_x = (v_ray->coord_x) / 30;
		if (v_ray->angle < (PI / 2) || v_ray->angle > (3 * PI / 2))
			map_x = (v_ray->coord_x + 30) / 30;
		if (map_y < 0 || map_x < 0
			|| map_y > map_data->size.y || map_x > map_data->size.x
			|| map_data->map[map_y][map_x] == '1')
		{
			v_ray->dist_from_player = ft_distance(player->coord.x,
					player->coord.y, v_ray->coord_x, v_ray->coord_y);
			return ;
		}
		v_ray->coord_y += v_ray->offset_y;
		v_ray->coord_x += v_ray->offset_x;
		dof += 1;
	}
}

/*
 *	***** ft_vert_check *****
 *
 *	DESCRIPTION:
 *		Performs the checks for the vertical intersections.
 *		First finds the intersection with the first gridline,
 *		then finds the offset (size of a grid square),
 *		then looks until a wall is seen.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_vert_check(t_player *player, t_map_data *map_data, t_ray *v_ray,
				int max_dof)
{
	double	negtan;

	negtan = -tan(v_ray->angle);
	if (negtan > 100)
		negtan = 100;
	if (negtan < -100)
		negtan = -100;
	if (v_ray->angle > (PI / 2) && v_ray->angle < (3 * PI / 2))
		ft_vert_looking_left(player, v_ray, map_data->map_block_size, negtan);
	if (v_ray->angle < (PI / 2) || v_ray->angle > (3 * PI / 2))
		ft_vert_looking_right(player, v_ray, map_data->map_block_size, negtan);
	if (v_ray->angle == (PI / 2) || v_ray->angle == (3 * PI / 2))
		ft_vert_looking_up_down(player, v_ray);
	ft_vert_dof(player, map_data, v_ray, max_dof);
	return ;
}
