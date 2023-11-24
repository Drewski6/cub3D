/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:55:09 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 12:39:09 by dpentlan         ###   ########.fr       */
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
	// ft_paint_bucket(&engine->map_image, &map, MAP_X, MAP_Y);

void	ft_draw_map(t_engine *engine, t_map_data *map_data, t_player *player)
{
	t_rgb	map;

	map = (t_rgb){40, 40, 40};
	(void) map_data;
	(void)engine;
	(void) map;
	ft_draw_player(player);
}
