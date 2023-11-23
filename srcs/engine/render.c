/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 23:12:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "cub3D.h"

bool	ft_render(t_map_data *map_data, t_engine *engine, t_player *player)
{
	ft_draw_background(engine, &engine->bg_image, &map_data->f, &map_data->c);
	ft_draw_map(engine);
	ft_draw_player(player);
	return (0);
}
