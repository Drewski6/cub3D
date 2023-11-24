/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:23:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 11:34:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "engine.h"
#include "libft.h"
#include "map_parsing.h"
#include "mlx.h"
#include <stdlib.h>

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
	if (engine->lst_images)
		ft_free_lst_images(&engine->lst_images);
	if (engine->mlx_ptr)
	{
		mlx_destroy_display(engine->mlx_ptr);
		free(engine->mlx_ptr);
		engine->mlx_ptr = NULL;
	}
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
		|| ft_add_image(&engine->lst_images, engine->mlx_ptr,
			BG_IMAGE, (t_point){WIN_X, WIN_Y}) < 0
		|| ft_add_image(&engine->lst_images, engine->mlx_ptr,
			MAP_IMAGE, (t_point){MAP_X, MAP_Y}) < 0
	)
		return (ft_putstr_fd("Error\nCould not initialize images.\n", 2), 1);
	return (0);
}
