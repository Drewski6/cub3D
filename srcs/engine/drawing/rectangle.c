/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:42:53 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 00:11:16 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "engine.h"

/*
 *	***** ft_img_buf_set_px_color *****
 *
 *	DESCRIPTION:
 *		Depending on the endian, writes a color to the image buffer at the pixel
 *		located at x and y.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_img_buf_set_px_color(t_image *image, t_rgb *color, int x, int y)
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
}

/*
 *	***** ft_paint_bucket *****
 *
 *	DESCRIPTION:
 *		My first basic coloring function. Starting from position (0, 0) changes
 *		the color in the image buffer until position (x, y) using color 'color'.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_paint_bucket(t_image *image, t_rgb *color, int x, int y)
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
}
