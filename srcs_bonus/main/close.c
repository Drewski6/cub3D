/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:24:51 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/01 15:16:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "map_parsing.h"
#include <stdlib.h>

/*
 *	***** ft_close_cub3d *****
 *
 *	DESCRIPTION:
 *		For use with mlx_hook if the X in the window bar is clicked.
 *		Returns int because mlx_hook requires an int return, but function never
 *		returns.
 *		Takes a special t_clear struct which only contains pointers to freeable
 *		structs.
 *	RETURN:
 *		Function shouldn't return. Used with mlx_hook if the x in the window
 *		is pressed.
 *		Also used with mlx_key_hook if ESC key is pressed.
 */

int	ft_close_cub3d(t_clear *clear)
{
	ft_free_engine((t_engine *)clear->engine);
	ft_free_map_data((t_map_data *)clear->map_data);
	exit(EXIT_SUCCESS);
	return (0);
}
