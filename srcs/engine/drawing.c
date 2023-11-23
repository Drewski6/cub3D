/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:42:53 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 22:44:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "engine.h"

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
