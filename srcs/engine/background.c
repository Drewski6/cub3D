/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:49:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 09:34:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"

/*
 *	***** ft_draw_background *****
 *
 *	DESCRIPTION:
 *		Adds the floor and ceiling colors to the background image and puts that
 *		image to the window.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_draw_background(t_engine *engine,
						t_image *bg_image, t_rgb *f, t_rgb *c)
{
	ft_paint_bucket(bg_image, f, WIN_X, WIN_Y);
	ft_paint_bucket(bg_image, c, WIN_X, WIN_Y / 2);
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		bg_image->img_ptr, 0, 0);
}
