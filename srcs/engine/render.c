/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 09:39:16 by dpentlan         ###   ########.fr       */
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
	(void) player;
	if (0
		|| ft_create_rect_image(engine, BG_IMAGE_C, (t_point){WIN_X, WIN_Y / 2},
		map_data->c)
		|| ft_create_rect_image(engine, BG_IMAGE_F, (t_point){WIN_X, WIN_Y / 2},
		map_data->f)
		|| ft_create_rect_image(engine, MAP_BG,
		(t_point){map_data->size.x * map_data->map_block_size,
		map_data->size.y * map_data->map_block_size},
		(t_rgb){255, 255, 255})
		|| ft_create_rect_image(engine, PLAYER,
		(t_point){MAP_SIZE / 100, MAP_SIZE / 100},
		(t_rgb){0, 100, 255})
	)
		return (1);
	if (ft_draw_map(engine, map_data))
		return (1);
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

bool	ft_render(t_engine *engine, t_map_data *map_data, t_player *player)
{
	(void) map_data;
	(void) player;
	if (0
		|| ft_send_image_to_window(engine, engine->lst_images, BG_IMAGE_C,
			(t_point){0, 0})
		|| ft_send_image_to_window(engine, engine->lst_images, BG_IMAGE_F,
			(t_point){0, WIN_Y / 2})
		|| ft_send_image_to_window(engine, engine->lst_images, MAP_BG,
			(t_point){MAP_ORIG_X, MAP_ORIG_Y})
		|| ft_send_image_to_window(engine, engine->lst_images, PLAYER,
			(t_point){player->pos.x, player->pos.y})
	)
		return (1);
	return (0);
}
