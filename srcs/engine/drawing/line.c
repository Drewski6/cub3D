/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:24:28 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/28 18:38:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "math.h"
#include "ft_printf.h"
#include <stdio.h>

/*
 *	***** ft_bresenhams_line *****
 *
 *	DESCRIPTION:
 *		My implementation of the bresenham line algorithm for drawing lines on
 *		coordinate systems.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 *		This function does not return error. Bool so it can be used in if statements.
 */

bool	ft_bresenhams_line(t_engine *engine,
						t_point from, t_point to, int color)
{
	int		px_count;
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;

	delta_x = to.x - from.x;
	delta_y = to.y - from.y;
	px_count = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= px_count;
	delta_y /= px_count;
	pixel_x = (double) from.x;
	pixel_y = (double) from.y;
	while (px_count > 0)
	{
		mlx_pixel_put(engine->mlx_ptr, engine->win_ptr,
			(int)pixel_x, (int)pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		px_count--;
	}
	return (0);
}
