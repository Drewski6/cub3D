/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:35:11 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 13:39:11 by dpentlan         ###   ########.fr       */
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
	int		bs;

	clear = param;
	bs = clear->map_data->map_block_size;
	if (key == ESC)
		ft_close_cub3d(param);
	else if (key == W_KEY)
		ft_move_player(clear->player, FORWARD_DIR, bs);
	else if (key == A_KEY)
		ft_move_player(clear->player, LEFT_DIR, bs);
	else if (key == S_KEY)
		ft_move_player(clear->player, BACKWARD_DIR, bs);
	else if (key == D_KEY)
		ft_move_player(clear->player, RIGHT_DIR, bs);
	else if (key == L_ARROW)
		ft_printf("Key Press: Left Arrow\n");
	else if (key == R_ARROW)
		ft_printf("Key Press: Right Arrow\n");
	else if (key == D_ARROW)
		ft_printf("Key Press: Down Arrow\n");
	else if (key == U_ARROW)
		ft_printf("Key Press: Up Arrow\n");
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
