/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:35:11 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 13:47:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	if (key == ESC)
		ft_close_cub3d(param);
	else if (key == W_KEY)
		ft_printf("W Key Pressed\n");
	else if (key == A_KEY)
		ft_printf("A Key Pressed\n");
	else if (key == S_KEY)
		ft_printf("S Key Pressed\n");
	else if (key == D_KEY)
		ft_printf("D Key Pressed\n");
	else if (key == L_ARROW)
		ft_printf("Left Arrow Key Pressed\n");
	else if (key == R_ARROW)
		ft_printf("Right Arrow Key Pressed\n");
	else if (key == D_ARROW)
		ft_printf("Down Arrow Key Pressed\n");
	else if (key == U_ARROW)
		ft_printf("Up Arrow Key Pressed\n");
	else
		ft_printf("Key: %d\n", key);
	return (0);
}
