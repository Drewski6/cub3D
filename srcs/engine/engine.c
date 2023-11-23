/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:23:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 22:27:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "engine.h"
#include "libft.h"
#include "map_parsing.h"
#include "mlx.h"
#include <stdlib.h>

/*
 *	***** ft_free_image *****
 *
 *	DESCRIPTION:
 *		Frees an image and reinitialiezes its struct values.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_free_image(t_image *image, void *mlx_ptr)
{
	if (image->img_ptr)
	{
		mlx_destroy_image(mlx_ptr, image->img_ptr);
		image->img_ptr = NULL;
	}
	image->endian = 0;
	image->size_line = 0;
	image->bits_per_pixel = 0;
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
	if (engine->bg_image.img_ptr)
		ft_free_image(&engine->bg_image, engine->mlx_ptr);
	if (engine->map_image.img_ptr)
		ft_free_image(&engine->map_image, engine->mlx_ptr);
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

bool	ft_images_init(t_image *image, void *mlx_ptr, int x, int y)
{
	image->img_ptr = mlx_new_image(mlx_ptr,
			x, y);
	if (!image->img_ptr)
		return (ft_putstr_fd("Error\nCould not initialize image.\n", 2), 1);
	image->bits_per_pixel = 0;
	image->size_line = 0;
	image->endian = 0;
	image->img_buf = NULL;
	image->img_buf = mlx_get_data_addr(
			image->img_ptr,
			&image->bits_per_pixel,
			&image->size_line,
			&image->endian);
	if (!image->img_buf)
		return (ft_putstr_fd("Error\nCould not initialize image.\n", 2), 1);
	return (0);
}

/*
 *	***** ft_engine_init *****
 *
 *	DESCRIPTION:
 *		Initializes the mlx pointer and the window pointer and the images.
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
	if (0
		|| ft_images_init(&engine->bg_image, engine->mlx_ptr, WIN_X, WIN_Y)
		|| ft_images_init(&engine->map_image, engine->mlx_ptr, MAP_X, MAP_Y)
	)
		return (ft_putstr_fd("Error\nCould not initialize images.\n", 2), 1);
	return (0);
}
