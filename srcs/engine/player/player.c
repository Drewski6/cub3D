/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:02:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/28 18:31:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "engine.h"
#include "mlx.h"
#include "stdbool.h"
#include "cub3D.h"
#include "libft.h"
#include "math.h"
#include <stdio.h>

/*
 *	***** ft_rotate_player *****
 *
 *	DESCRIPTION:
 *		Changes the player's angle of rotation and sets the new player delta.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_rotate_player(t_player *player, t_direction direction)
{
	if (direction == LEFT_DIR)
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * PI;
		player->delta.x = cos(player->angle) * MOVE_SPEED;
		player->delta.y = sin(player->angle) * MOVE_SPEED;
	}
	if (direction == RIGHT_DIR)
	{
		player->angle += 0.1;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
		player->delta.x = cos(player->angle) * MOVE_SPEED;
		player->delta.y = sin(player->angle) * MOVE_SPEED;
	}
}

/*
 *	***** ft_move_player *****
 *
 *	DESCRIPTION:
 *		Edit the players position varaible.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_move_player(t_player *player, t_direction direction)
{
	if (direction == FORWARD_DIR)
	{
		player->pos.x += player->delta.x;
		player->pos.y += player->delta.y;
	}
	if (direction == BACKWARD_DIR)
	{
		player->pos.x -= player->delta.x;
		player->pos.y -= player->delta.y;
	}
}

/*
 *	***** ft_player_init *****
 *
 *	DESCRIPTION:
 *		Initialize variables in the player struct.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 *	NOTE:
 *		Function does not return a value other than 0 because it's use in a
 *		large if statement for the return.
 */

bool	ft_player_init(t_player *player, t_map_data *map_data)
{
	player->pos.x = map_data->start_pos.x + 0.5;
	player->pos.y = map_data->start_pos.y + 0.5;
	player->coord.x = 0;
	player->coord.y = 0;
	player->size = map_data->map_block_size / 3;
	player->delta.x = cos(player->angle) * MOVE_SPEED;
	player->delta.y = sin(player->angle) * MOVE_SPEED;
	player->angle = 0;
	return (0);
}

/*
 *	***** ft_update_player_coords *****
 *
 *	DESCRIPTION:
 *		Uses the player position (stored as a pair of doubles) and finds
 *		the relative position on the map to draw the player.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_update_player_coords(t_player *player, int block_size)
{
	player->coord.x = (player->pos.x * block_size) - block_size;
	player->coord.y = (player->pos.y * block_size) - block_size;
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
	t_image	*map;

	(void) map_data;
	map = ft_get_image(engine->lst_images, MINI_MAP);
	if (!map)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	ft_update_player_coords(player, map_data->map_block_size);
	ft_px_put_rect(engine, (t_rect){
		(t_point){MAP_ORIG_X + player->coord.x - (player->size / 2),
		MAP_ORIG_Y + player->coord.y - (player->size / 2)},
		(t_point){MAP_ORIG_X + player->coord.x + (player->size / 2),
		MAP_ORIG_Y + player->coord.y + (player->size / 2)},
		(t_rgb){PLAYER_R, PLAYER_G, PLAYER_B}});
	return (0);
}
