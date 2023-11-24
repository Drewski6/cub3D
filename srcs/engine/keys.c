/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:35:11 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 09:40:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "cub3D.h"

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
		ft_printf("Key Press: W\n");
	else if (key == A_KEY)
		ft_printf("Key Press: A\n");
	else if (key == S_KEY)
		ft_printf("Key Press: S\n");
	else if (key == D_KEY)
		ft_printf("Key Press: D\n");
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
