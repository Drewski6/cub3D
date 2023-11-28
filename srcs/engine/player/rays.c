/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:23:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/28 10:30:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

bool	ft_draw_rays(t_engine *engine, t_player *player)
{
	if (0
		|| ft_bresenhams_line(engine, (t_point){0, 0},
		(t_point){player->coord.x + player->size,
		player->coord.y + player->size},
		ft_color_to_int((t_rgb){255, 255, 0}))
	)
		return (1);
	return (0);
}
