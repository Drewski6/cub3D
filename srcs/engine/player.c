/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:02:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 10:09:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "stdbool.h"
#include "cub3D.h"
#include <stdio.h>

/*
 *	***** ft_player_init *****
 *
 *	DESCRIPTION:
 *		Initialize variables in the player struct.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_player_init(t_player *player, t_map_data *map_data)
{
	player->pos.x = map_data->start_pos.x + 0.5;
	player->pos.y = map_data->start_pos.y + 0.5;
	return (0);
}

/*
 *	***** ft_draw_player *****
 *
 *	DESCRIPTION:
 *		Draws the players position on the map for visual representations.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_draw_player(t_engine *engine, t_map_data *map_data, t_player *player)
{
	(void) engine;
	(void) map_data;
	(void) player;
	printf("player x(%f) y(%f)\n", player->pos.x, player->pos.y);
	return (0);
}
