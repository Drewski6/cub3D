/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:22:53 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 12:51:20 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3D.h"
#include "ft_printf.h"
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
 *	***** ft_draw_map *****
 *
 *	DESCRIPTION:
 *		Finds the map background image and draws blocks on it to create a map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_draw_map(t_engine *engine, t_map_data *map_data)
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
