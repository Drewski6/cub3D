/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:35:11 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 15:01:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "cub3D.h"
#include "keys.h"
#include "engine.h"

/*
 *	***** ft_key_press *****
 *
 *	DESCRIPTION:
 *		Called when a key press event is detected. Use as a switch for key 
 *		related events.
 *	RETURN:
 *		Returns int for mlx_key_hook.
 */

int	ft_key_press(int key, void *param)
{
	t_clear	*clear;

	clear = param;
	if (key == ESC)
		ft_close_cub3d(param);
	else if (key == W_KEY)
		ft_move_player(clear->player, FORWARD_DIR);
	else if (key == A_KEY)
		ft_move_player(clear->player, LEFT_DIR);
	else if (key == S_KEY)
		ft_move_player(clear->player, BACKWARD_DIR);
	else if (key == D_KEY)
		ft_move_player(clear->player, RIGHT_DIR);
	else if (key == L_ARROW)
		ft_rotate_player(clear->player, TURN_LEFT);
	else if (key == R_ARROW)
		ft_rotate_player(clear->player, TURN_RIGHT);
	ft_render(clear);
	return (0);
}

/*
 *	***** ft_key_release *****
 *
 *	DESCRIPTION:
 *		Action to take on key release.
 *	RETURN:
 *		Return type of int required by mlx.
 */

int	ft_key_release(int key, void *param)
{
	(void) key;
	(void) param;
	return (0);
}
