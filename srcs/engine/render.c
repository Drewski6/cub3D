/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 17:15:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "engine.h"
#include "map_parsing.h"

bool	ft_paint_bucket(void *img_ptr, int x, int y)
{
	(void) img_ptr;
	(void) x;
	(void) y;
	return (0);
}

bool	ft_render(t_map_data *map_data, t_engine *engine)
{
	(void) map_data;
	ft_paint_bucket(engine->bg_img_ptr, WIN_X, WIN_Y);
	return (0);
}
