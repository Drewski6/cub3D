/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:23:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 17:50:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "engine.h"
#include "math.h"
#include "cub3D.h"
#include <stdio.h>
#include "libft.h"

/*
 *	***** ft_set_ray_angles *****
 *
 *	DESCRIPTION:
 *		Sets the ray's angle according to how large the field of view is set.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_init_ray(t_player *player, t_ray *ray, int ray_num)
{
	double	fov;
	double	offset;

	ray->dist_from_player = 1000000;
	fov = FOV;
	offset = fov * 4;
	ray->angle = player->angle + ((ray_num - offset) * (RADS_PER_DEG / 4));
	if (ray->angle > (2 * PI))
		ray->angle -= (2 * PI);
	if (ray->angle < 0)
		ray->angle += (2 * PI);
}

/*
 *	***** ft_set_return_ray_values *****
 *
 *	DESCRIPTION:
 *		desc
 *	RETURN:
 *		ret
 */

void	ft_set_return_ray_values(t_player *player, t_ray *ray,
							t_ray *h_ray, t_ray *v_ray)
{
	if (h_ray->dist_from_player < v_ray->dist_from_player)
	{
		ray->coord_x = h_ray->coord_x + MAP_ORIG_X;
		ray->coord_y = h_ray->coord_y + MAP_ORIG_Y;
		ray->dist_from_player = ft_fix_fisheye(player->angle,
				h_ray->angle, h_ray->dist_from_player);
		ray->color = (t_rgb){255, 255, 255};
	}
	else
	{
		ray->coord_x = v_ray->coord_x + MAP_ORIG_X;
		ray->coord_y = v_ray->coord_y + MAP_ORIG_Y;
		ray->dist_from_player = ft_fix_fisheye(player->angle,
				v_ray->angle, v_ray->dist_from_player);
		ray->color = (t_rgb){200, 200, 200};
	}
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

void	ft_draw_one_ray(t_player *player, t_map_data *map_data,
					t_ray *ray, int ray_num)
{
	t_ray		h_ray;
	t_ray		v_ray;
	int			max_dof;

	max_dof = map_data->size.y;
	if (map_data->size.x > map_data->size.y)
		max_dof = map_data->size.x;
	ft_bzero(&h_ray, sizeof(t_ray));
	ft_bzero(&v_ray, sizeof(t_ray));
	ft_init_ray(player, &h_ray, ray_num);
	ft_init_ray(player, &v_ray, ray_num);
	ft_horiz_check(player, map_data, &h_ray, max_dof);
	ft_vert_check(player, map_data, &v_ray, max_dof);
	ft_set_return_ray_values(player, ray, &h_ray, &v_ray);
}

/*
 *	***** ft_dir_ray *****

 *
 *	DESCRIPTION:
 *		Draws the ray that indicates the player's direction on the mini map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_dir_ray(t_engine *engine, t_player *player, t_map_data *map_data)
{
	double	x_start;
	double	y_start;

	x_start = player->coord.x + MAP_ORIG_X;
	y_start = player->coord.y + MAP_ORIG_Y;
	ft_bresenhams_line(engine,
		(t_point){x_start, y_start},
		(t_point){x_start + player->delta.x * (map_data->bs * 5),
		y_start + player->delta.y * (map_data->bs * 5)},
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
 *	NOTE:
 *		Saving this piece of code for if I want to draw map rays.
 *
		ft_bresenhams_line(engine,
			(t_point){player->coord.x + MAP_ORIG_X,
			player->coord.y + MAP_ORIG_Y},
			(t_point){ray.coord_x, ray.coord_y},
			ft_color_to_int((t_rgb){0, 255, 0}));
 */

bool	ft_draw_rays(t_engine *engine, t_player *player, t_map_data *map_data)
{
	int		ray_num;
	t_ray	ray;
	int		vert_bar_height;
	int		h_offset;
	int		v_offset;

	ray_num = 0;
	h_offset = WIN_X / 400;
	ft_bzero(&ray, sizeof(t_ray));
	while (ray_num < 400)
	{
		ft_draw_one_ray(player, map_data, &ray, ray_num);
		vert_bar_height = (map_data->bs * WIN_X) / ray.dist_from_player;
		if (vert_bar_height > WIN_Y)
			vert_bar_height = WIN_Y;
		v_offset = WIN_Y / 2 - (vert_bar_height / 2);
		// ft_bresenhams_line(engine,
		// 	(t_point){player->coord.x + MAP_ORIG_X,
		// 	player->coord.y + MAP_ORIG_Y},
		// 	(t_point){ray.coord_x, ray.coord_y},
		// 	ft_color_to_int((t_rgb){0, 255, 0}));
		ft_px_put_rect(engine,
			(t_rect){(t_point){h_offset * ray_num, v_offset},
			(t_point){(h_offset * ray_num) + h_offset,
			vert_bar_height + v_offset}, ray.color,
		});
		ray_num++;
	}
	ft_dir_ray(engine, player, map_data);
	return (0);
}
