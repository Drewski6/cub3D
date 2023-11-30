/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/28 19:55:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
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

bool	ft_prerender(t_engine *engine, t_map_data *map_data)
{
	if (0
		|| ft_create_rect_image(engine, BG_IMAGE_C, (t_point){WIN_X, WIN_Y / 2},
		map_data->c)
		|| ft_create_rect_image(engine, BG_IMAGE_F, (t_point){WIN_X, WIN_Y / 2},
		map_data->f)
		|| ft_create_rect_image(engine, MINI_MAP,
		(t_point){map_data->size.x * map_data->map_block_size,
		map_data->size.y * map_data->map_block_size},
		(t_rgb){MAP_BG_R, MAP_BG_G, MAP_BG_B})
		|| ft_draw_map(engine, map_data)
	)
		return (1);
	return (0);
}

/*
 *	***** ft_render *****
 *
 *	DESCRIPTION:
 *		Parent function for all the drawing functions that need to be called
 *		in order to create a single image.
 *		Used by mlx_loop_hook which means this function is called everytime
 *		we are in between key events.
 *		Essencially this is the refresh.
 *	RETURN:
 *		Returns an int as required by mlx.
 */

int	ft_render(t_clear *clear)
{
	t_engine	*engine;
	t_map_data	*map_data;
	t_player	*player;

	engine = clear->engine;
	map_data = clear->map_data;
	player = clear->player;
	if (0
		|| ft_send_image_to_window(engine, engine->lst_images, BG_IMAGE_C,
			(t_point){0, 0})
		|| ft_send_image_to_window(engine, engine->lst_images, BG_IMAGE_F,
			(t_point){0, WIN_Y / 2})
		|| ft_send_image_to_window(engine, engine->lst_images, MINI_MAP,
			(t_point){MAP_ORIG_X, MAP_ORIG_Y})
		|| ft_draw_player(engine, map_data, player)
		|| ft_draw_rays(engine, player, map_data)
	)
		return (1);
	return (0);
}
