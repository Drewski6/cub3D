/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:42:53 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 14:26:32 by dpentlan         ###   ########.fr       */
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

void	ft_img_buf_set_px_color(t_image *image, t_rgb color, int x, int y)
{
	int	offset;

	offset = (y * image->size_line) + (x * 4);
	if (image->endian == 1)
	{
		image->img_buf[offset + 0] = 1;
		image->img_buf[offset + 1] = (unsigned char)(color.red);
		image->img_buf[offset + 2] = (unsigned char)(color.green);
		image->img_buf[offset + 3] = (unsigned char)(color.blue);
	}
	else
	{
		image->img_buf[offset + 0] = (unsigned char)(color.blue);
		image->img_buf[offset + 1] = (unsigned char)(color.green);
		image->img_buf[offset + 2] = (unsigned char)(color.red);
		image->img_buf[offset + 3] = 1;
	}
}

/*
 *	***** ft_paint_bucket *****
 *
 *	DESCRIPTION:
 *		My first basic coloring function. Starting from position (rect top_left)
 *		changes the color in the image buffer until position (rect bottom_right)
 *		using color (rect color).
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_paint_bucket(t_image *image, t_rect rect)
{
	int		y_start;
	int		x_start;
	int		y_end;
	int		x_end;

	y_end = rect.bottom_right.y;
	x_end = rect.bottom_right.x;
	y_start = rect.top_left.y;
	while (y_start < y_end)
	{
		x_start = rect.top_left.x;
		while (x_start < x_end)
		{
			ft_img_buf_set_px_color(image, rect.color, x_start, y_start);
			x_start++;
		}
		y_start++;
	}
}
