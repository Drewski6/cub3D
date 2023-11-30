/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:23:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 09:04:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "engine.h"
#include "math.h"
#include "cub3D.h"
#include <stdio.h>
#include "libft.h"

/*
 *	***** ft_distance *****
 *
 *	DESCRIPTION:
 *		Calculate the distance between two points using the pythagorean theorm.
 *	RETURN:
 *		Returns as a double the distance between two points.
 */

double	ft_distance(double pt1x, double pt1y, double pt2x, double pt2y)
{
	return (
		sqrt(((pt2x - pt1x) * (pt2x - pt1x))
			+ ((pt2y - pt1y) * (pt2y - pt1y))));
}

/*
 *	***** ft_line_check *****
 *
 *	DESCRIPTION:
 *		Sets up both h_ray and v_ray and sends them to their corresponding
 *		checker functions for evaluation.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_line_check(t_player *player, t_map_data *map_data, t_full_ray *ray)
{
	int	max_dof;

	if (map_data->size.x > map_data->size.y)
		max_dof = map_data->size.x;
	else
		max_dof = map_data->size.y;
	ray->h_ray.angle = player->angle;
	ray->h_ray.dist_from_player = 1000000;
	ray->v_ray.angle = player->angle;
	ray->v_ray.dist_from_player = 1000000;
	ft_horiz_check(player, map_data, &ray->h_ray, max_dof);
	ft_vert_check(player, map_data, &ray->v_ray, max_dof);
}

/*
 *	***** ft_draw_one_ray *****
 *
 *	DESCRIPTION:
 *		Common function for returning the information for one ray.
 *	RETURN:
 *		Returns a t_point struct which is two integer values of the coordinates
 *		where the ray should end.
 *		Player position should be the starting point.
 */

t_point	ft_draw_one_ray(t_player *player,
					t_map_data *map_data, int ray_num)
{
	t_full_ray	ray;

	(void) ray_num;
	ft_bzero(&ray, sizeof(t_full_ray));
	ft_line_check(player, map_data, &ray);
	if (ray.h_ray.dist_from_player < ray.v_ray.dist_from_player)
	{
		ray.final.x = ray.h_ray.coord_x + MAP_ORIG_X;
		ray.final.y = ray.h_ray.coord_y + MAP_ORIG_Y;
	}
	else
	{
		ray.final.x = ray.v_ray.coord_x + MAP_ORIG_X;
		ray.final.y = ray.v_ray.coord_y + MAP_ORIG_Y;
	}
	return (ray.final);
}

/*
 *	***** ft_dir_ray *****

 *
 *	DESCRIPTION:
 *		Draws the ray that indicates the player's direction on the mini map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_dir_ray(t_engine *engine, t_player *player)
{
	ft_bresenhams_line(engine,
		(t_point){player->coord.x + player->size,
		player->coord.y + player->size},
		(t_point){(player->coord.x + player->size) + player->delta.x * 150,
		(player->coord.y + player->size) + player->delta.y * 150},
		ft_color_to_int((t_rgb){PLAYER_R, PLAYER_G, PLAYER_B}));
	return (0);
}

/*
 *	***** ft_draw_rays *****
 *
 *	DESCRIPTION:
 *		Draw function for the player's rays on the map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_draw_rays(t_engine *engine, t_player *player, t_map_data *map_data)
{
	int	i;
	int	num_rays;

	i = 0;
	num_rays = 1;
	while (i < num_rays)
	{
		ft_bresenhams_line(engine,
			(t_point){player->coord.x + MAP_ORIG_X,
			player->coord.y + MAP_ORIG_Y},
			ft_draw_one_ray(player, map_data, i),
			ft_color_to_int((t_rgb){255, 255, 0}));
		i++;
	}
	ft_dir_ray(engine, player);
	return (0);
}
