/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:55:09 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 09:26:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"

/*
 *	***** ft_draw_map *****
 *
 *	DESCRIPTION:
 *		Draws the displayable map for the player.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_draw_map(t_engine *engine, t_player *player)
{
	t_rgb	map;

	map = (t_rgb){40, 40, 40};
	ft_paint_bucket(&engine->map_image, &map, MAP_X, MAP_Y);
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		engine->map_image.img_ptr, 5, 5);
	ft_draw_player(player);
}
