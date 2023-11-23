/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:23:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 17:11:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "engine.h"
#include "libft.h"
#include "map_parsing.h"
#include "mlx.h"
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

/*
 *	***** ft_free_engine *****
 *
 *	DESCRIPTION:
 *		Free and destroy the mlx pointers.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_free_engine(t_engine *engine)
{
	if (engine->win_ptr)
	{
		mlx_destroy_window(engine->mlx_ptr, engine->win_ptr);
		engine->win_ptr = NULL;
	}
	if (engine->bg_img_ptr)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->bg_img_ptr);
		engine->bg_img_ptr = NULL;
	}
	if (engine->map_img_ptr)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->map_img_ptr);
		engine->map_img_ptr = NULL;
	}
	if (engine->mlx_ptr)
	{
		mlx_destroy_display(engine->mlx_ptr);
		free(engine->mlx_ptr);
		engine->mlx_ptr = NULL;
	}
}

/*
 *	***** ft_images_init *****
 *
 *	DESCRIPTION:
 *		Initializes the images to be used in cub3D
 *	RETURN:
 *		ret
 */

bool	ft_images_init(t_engine *engine)
{
	engine->bg_img_ptr = mlx_new_image(engine->mlx_ptr,
			WIN_X, WIN_Y);
	if (!engine->bg_img_ptr)
		return (ft_putstr_fd("Error\nCould not initialize bg_img_ptr.\n", 2), 1);
	engine->map_img_ptr = mlx_new_image(engine->mlx_ptr,
			MAP_X, MAP_Y);
	if (!engine->map_img_ptr)
		return (ft_putstr_fd("Error\nCould not initialize map_img_ptr.\n", 2), 1);
	return (0);
}

/*
 *	***** ft_engine_init *****
 *
 *	DESCRIPTION:
 *		Initializes the mlx pointer and the window pointer.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_engine_init(t_engine *engine)
{
	engine->mlx_ptr = mlx_init();
	if (!engine->mlx_ptr)
		return (ft_putstr_fd("Error\nCould not initialize mlx_ptr.\n", 2), 1);
	engine->win_ptr = mlx_new_window(engine->mlx_ptr,
			WIN_X, WIN_Y, WIN_NAME);
	if (!engine->win_ptr)
		return (ft_putstr_fd("Error\nCould not initialize win_ptr.\n", 2), 1);
	return (0);
}
