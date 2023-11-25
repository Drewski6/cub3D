/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:22:53 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 08:51:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3D.h"
#include "ft_printf.h"
#include "libft.h"

/*
 *	***** ft_draw_map *****
 *
 *	DESCRIPTION:
 *		Finds the map background image and draws blocks on it to create a map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_draw_map(t_engine *engine, t_map_data *map_data)
{
	t_image	*map;

	(void) map_data;
	map = ft_get_image(engine->lst_images, MAP_BG);
	if (!map)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	return (0);
}
