/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:55:09 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 12:50:36 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "libft.h"

/*
 *	***** ft_draw_map *****
 *
 *	DESCRIPTION:
 *		Draws the displayable map for the player.
 *	RETURN:
 *		Void function does not return a value.
 */

bool	ft_draw_map(t_engine *engine, t_map_data *map_data, t_player *player)
{
	t_rgb	map;
	t_image	*image;

	(void) map_data;
	map = (t_rgb){40, 40, 40};
	image = ft_get_image(engine->lst_images, MAP_IMAGE);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	ft_paint_bucket(image, &map, MAP_X, MAP_Y);
	ft_draw_player(player);
	return (0);
}
