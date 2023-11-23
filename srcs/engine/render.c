/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 18:44:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "map_parsing.h"
#include "mlx.h"
#include <stdbool.h>
#include "ft_printf.h"
#include "cub3D.h"

bool	ft_img_buf_set_px_color(t_image *image, t_rgb *color, int x, int y)
{
	int	offset;

	offset = (y * image->size_line) + (x * 4);
	if (image->endian == 1)
	{
		image->img_buf[offset + 0] = 1;
		image->img_buf[offset + 1] = (unsigned char)(color->red);
		image->img_buf[offset + 2] = (unsigned char)(color->green);
		image->img_buf[offset + 3] = (unsigned char)(color->blue);
	}
	else
	{
		image->img_buf[offset + 0] = (unsigned char)(color->blue);
		image->img_buf[offset + 1] = (unsigned char)(color->green);
		image->img_buf[offset + 2] = (unsigned char)(color->red);
		image->img_buf[offset + 3] = 1;
	}
	return (0);
}

bool	ft_paint_bucket(t_image *image, t_rgb *color, int x, int y)
{
	int		lx;
	int		ly;

	ly = 0;
	while (ly < y)
	{
		lx = 0;
		while (lx < x)
		{
			ft_img_buf_set_px_color(image, color, lx, ly);
			lx++;
		}
		ly++;
	}
	return (0);
}

bool	ft_render(t_map_data *map_data, t_engine *engine)
{
	ft_paint_bucket(&engine->bg_image, &map_data->f, WIN_X, WIN_Y);
	ft_paint_bucket(&engine->bg_image, &map_data->c, WIN_X, WIN_Y / 2);
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		engine->bg_image.img_ptr, 0, 0);
	return (0);
}
