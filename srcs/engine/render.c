/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 12:38:55 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "cub3D.h"
#include "libft.h"

/*
 *	***** ft_prerender *****
 *
 *	DESCRIPTION:
 *		Initializes most images that will not change during execution of the
 *		program.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_prerender(t_engine *engine, t_map_data *map_data, t_player *player)
{
	t_image	*image;

	(void) map_data;
	(void) player;
	if (0
		|| ft_add_image(&engine->lst_images, engine->mlx_ptr,
			BG_IMAGE, (t_point){WIN_X, WIN_Y})
		|| ft_add_image(&engine->lst_images, engine->mlx_ptr,
			MAP_IMAGE, (t_point){MAP_X, MAP_Y})
	)
		return (ft_putstr_fd("Error\nCould not initialize images.\n", 2), 1);
	image = ft_get_image(engine->lst_images, BG_IMAGE);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	ft_draw_background(image, &map_data->f, &map_data->c);
	ft_draw_map(engine, map_data, player);
	return (0);
}

/*
 *	***** ft_render *****
 *
 *	DESCRIPTION:
 *		Parent function for all the drawing functions that need to be called
 *		in order to create a single image.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */
	// mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
	// 	engine->map_image.img_ptr, 5, 5);

bool	ft_render(t_engine *engine, t_map_data *map_data, t_player *player)
{
	t_image	*image;

	(void) engine;
	(void) map_data;
	(void) player;
	image = ft_get_image(engine->lst_images, BG_IMAGE);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during render.\n", 2), 1);
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		image->img_ptr, 0, 0);
	return (0);
}
