/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:49:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 22:53:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"

void	ft_draw_background(t_engine *engine,
						t_image *bg_image, t_rgb *f, t_rgb *c)
{
	ft_paint_bucket(bg_image, f, WIN_X, WIN_Y);
	ft_paint_bucket(bg_image, c, WIN_X, WIN_Y / 2);
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		engine->bg_image.img_ptr, 0, 0);
}
