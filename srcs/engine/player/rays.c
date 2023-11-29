/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:23:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/29 15:47:10 by dpentlan         ###   ########.fr       */
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

t_ray	ft_vertical_line_check(t_player *player, t_map_data *map_data)
{
	t_ray	ray;
	int		num_rays;
	int		depth_of_field;
	double	negtan;
	int		map_x;
	int		map_y;
	int		max_dof;

	ray.dist_from_player = 1000000;
	if (map_data->size.x > map_data->size.y)
		max_dof = map_data->size.x;
	else
		max_dof = map_data->size.y;
	ft_bzero(&ray, sizeof(ray));
	ray.angle = player->angle;
	num_rays = 1;
	while (num_rays > 0)
	{
		depth_of_field = 0;
		negtan = -tan(ray.angle);
		if (negtan > 100)
			negtan = 100;
		if (negtan < -100)
			negtan = -100;
		if (ray.angle > (PI / 2) && ray.angle < (3 * PI / 2))
		{
			ray.coord_x = player->coord.x / 30 * 30 + 0.0001;
			ray.coord_y = (player->coord.x - ray.coord_x)
				* negtan + player->coord.y;
			ray.offset_x = -map_data->map_block_size;
			ray.offset_y = -ray.offset_x * negtan;
		}
		if (ray.angle < (PI / 2) || ray.angle > (3 * PI / 2))
		{
			ray.coord_x = player->coord.x / 30 * 30 + 30;
			ray.coord_y = (player->coord.x - ray.coord_x)
				* negtan + player->coord.y;
			ray.offset_x = map_data->map_block_size;
			ray.offset_y = -ray.offset_x * negtan;
		}
		if (ray.angle == 0)
		{
			ray.coord_x = player->coord.x / 30 * 30 + 30;
			ray.coord_y = player->coord.y;
			ray.offset_x = 30;
			ray.offset_y = 0;
		}
		if (ray.angle == PI)
		{
			ray.coord_x = player->coord.x;
			ray.coord_y = player->coord.y / 30 * 30;
			ray.offset_x = 30;
			ray.offset_y = 0;
		}
		while (depth_of_field < max_dof)
		{
			if (ray.angle > (PI / 2) && ray.angle < (3 * PI / 2))
			{
				map_y = (ray.coord_y + 30) / 30;
				map_x = (ray.coord_x) / 30;
			}
			if (ray.angle < (PI / 2) || ray.angle > (3 * PI / 2))
			{
				map_y = (ray.coord_y + 30) / 30;
				map_x = (ray.coord_x + 30) / 30;
			}
			if (map_y < 0 || map_x < 0
				|| map_y > map_data->size.y || map_x > map_data->size.x)
			{
				ray.dist_from_player = ft_distance(player->coord.x,
						player->coord.y, ray.coord_x, ray.coord_y);
				break ;
			}
			if (map_data->map[map_y][map_x] == '1')
			{
				depth_of_field = max_dof;
				ray.dist_from_player = ft_distance(player->coord.x,
						player->coord.y, ray.coord_x, ray.coord_y);
			}
			else
			{
				ray.coord_y += ray.offset_y;
				ray.coord_x += ray.offset_x;
				depth_of_field += 1;
			}
		}
		num_rays--;
	}
	return (ray);
}

/*
 *	***** ft_horizontal_line_check *****
 *
 *	DESCRIPTION:
 *		Draws the rays that extend to the first horizontal wall encountered.
 *	RETURN:
 *		ret
 */

t_ray	ft_horizontal_line_check(t_player *player, t_map_data *map_data)
{
	t_ray	ray;
	int		num_rays;
	int		depth_of_field;
	double	arctan;
	int		map_x;
	int		map_y;
	int		max_dof;

	ray.dist_from_player = 1000000;
	if (map_data->size.x > map_data->size.y)
		max_dof = map_data->size.x;
	else
		max_dof = map_data->size.y;
	ft_bzero(&ray, sizeof(ray));
	ray.angle = player->angle;
	num_rays = 1;
	while (num_rays > 0)
	{
		depth_of_field = 0;
		arctan = -1 / tan(ray.angle);
		if (arctan > 100)
			arctan = 100;
		if (arctan < -100)
			arctan = -100;
		if (ray.angle > PI)
		{
			ray.coord_y = player->coord.y / 30 * 30 + 0.0001;
			ray.coord_x = (player->coord.y - ray.coord_y)
				* arctan + player->coord.x;
			ray.offset_y = -map_data->map_block_size;
			ray.offset_x = -ray.offset_y * arctan;
		}
		if (ray.angle < PI)
		{
			ray.coord_y = player->coord.y / 30 * 30 + 30;
			ray.coord_x = (player->coord.y - ray.coord_y)
				* arctan + player->coord.x;
			ray.offset_y = map_data->map_block_size;
			ray.offset_x = -ray.offset_y * arctan;
		}
		if (ray.angle == 0)
		{
			ray.coord_y = player->coord.y;
			ray.coord_x = player->coord.x / 30 * 30 + 30;
			ray.offset_y = 0;
			ray.offset_x = 30;
		}
		if (ray.angle == PI)
		{
			ray.coord_y = player->coord.y;
			ray.coord_x = player->coord.x / 30 * 30;
			ray.offset_y = 0;
			ray.offset_x = 30;
		}
		while (depth_of_field < max_dof)
		{
			if (ray.angle > PI)
			{
				map_y = (ray.coord_y) / 30;
				map_x = (ray.coord_x + 30) / 30;
			}
			if (ray.angle < PI)
			{
				map_y = (ray.coord_y + 30) / 30;
				map_x = (ray.coord_x + 30) / 30;
			}
			if (map_y < 0 || map_x < 0 || map_y > map_data->size.y
				|| map_x > map_data->size.x)
			{
				ray.dist_from_player = ft_distance(player->coord.x,
						player->coord.y, ray.coord_x, ray.coord_y);
				break ;
			}
			if (map_data->map[map_y][map_x] == '1')
			{
				depth_of_field = max_dof;
				ray.dist_from_player = ft_distance(player->coord.x,
						player->coord.y, ray.coord_x, ray.coord_y);
			}
			else
			{
				ray.coord_y += ray.offset_y;
				ray.coord_x += ray.offset_x;
				depth_of_field += 1;
			}
		}
		num_rays--;
	}
	return (ray);
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

t_point	ft_draw_one_ray(t_player *player,
					t_map_data *map_data, int ray_num)
{
	t_ray	h_ray;
	t_ray	v_ray;
	t_ray	fin_ray;

	(void) ray_num;
	ft_bzero(&h_ray, sizeof(h_ray));
	ft_bzero(&v_ray, sizeof(v_ray));
	ft_bzero(&fin_ray, sizeof(fin_ray));
	h_ray = ft_horizontal_line_check(player, map_data);
	v_ray = ft_vertical_line_check(player, map_data);
	if (h_ray.dist_from_player < v_ray.dist_from_player)
	{
		fin_ray.coord_x = h_ray.coord_x;
		fin_ray.coord_y = h_ray.coord_y;
	}
	else
	{
		fin_ray.coord_x = v_ray.coord_x;
		fin_ray.coord_y = v_ray.coord_y;
	}
	return ((t_point){fin_ray.coord_x + MAP_ORIG_X,
		fin_ray.coord_y + MAP_ORIG_Y});
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
