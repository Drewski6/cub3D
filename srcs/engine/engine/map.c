/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:22:53 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/01 15:07:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"
#include "map_parsing.h"
#include "engine.h"
#include "libft.h"
#include "colors.h"

void	ft_draw_map_block(t_rgb color, t_image *image, int bs, t_point org)
{
	ft_paint_bucket(image, (t_rect){
		(t_point){(bs * org.x) - bs + 1, (bs * org.y) - bs + 1},
		(t_point){(bs * org.x) - 1, (bs * org.y) - 1},
		color});
}

/*
 *	***** ft_draw_mini_map *****
 *
 *	DESCRIPTION:
 *		Finds the map background image and draws blocks on it to create a map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_draw_mini_map(t_engine *engine, t_map_data *map_data)
{
	t_image	*map;
	int		x;
	int		y;

	map = ft_get_image(engine->lst_images, MINI_MAP);
	if (!map)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	y = 1;
	while (y <= map_data->size.y)
	{
		x = 1;
		while (x <= map_data->size.x)
		{
			if (map_data->map[y][x] == '1')
				ft_draw_map_block((t_rgb){MAP_FG_1_R, MAP_FG_1_G, MAP_FG_1_B},
					map, map_data->bs, (t_point){x, y});
			else if (map_data->map[y][x] != ' ')
				ft_draw_map_block((t_rgb){MAP_FG_0_R, MAP_FG_0_G, MAP_FG_0_B},
					map, map_data->bs, (t_point){x, y});
			x++;
		}
		y++;
	}
	return (0);
}

/*
 *	***** ft_draw_map_rays *****
 *
 *	DESCRIPTION:
 *		Draw function for the player's rays on the map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 *	NOTE:
 *		Saving this piece of code for if I want to draw map rays.
 *
 */

bool	ft_draw_map_rays(t_engine *engine, t_player *player,
					t_map_data *map_data)
{
	int		ray_num;
	t_ray	ray;
	int		vert_bar_height;

	ray_num = 0;
	ft_bzero(&ray, sizeof(t_ray));
	while (ray_num < WIN_X)
	{
		ft_draw_one_ray(player, map_data, &ray, ray_num);
		vert_bar_height = (map_data->bs * WIN_X) / ray.dist_from_player;
		if (vert_bar_height > WIN_Y)
			vert_bar_height = WIN_Y;
		ft_bresenhams_line(engine,
			(t_point){player->coord.x + MAP_ORIG_X,
			player->coord.y + MAP_ORIG_Y},
			(t_point){ray.coord_x, ray.coord_y},
			ft_color_to_int((t_rgb){0, 255, 0}));
		ray_num++;
	}
	ft_dir_ray(engine, player, map_data);
	return (0);
}
