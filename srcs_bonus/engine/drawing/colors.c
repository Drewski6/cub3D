/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:00:35 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 10:51:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3ddef.h"

/*
 *	***** ft_int_to_color *****
 *
 *	DESCRIPTION:
 *		Converts a color encoded as an integer into a t_rgb struct for ease of
 *		use.
 *	RETURN:
 *		Returns a t_rgb struct with appropriate values set.
 */

t_rgb	ft_int_to_color(int color)
{
	t_rgb	ret_color;
	char	*byte;

	ret_color = (t_rgb){0, 0, 0};
	byte = (char *)&color;
	ret_color.red = (unsigned char)byte[0];
	ret_color.green = (unsigned char)byte[1];
	ret_color.blue = (unsigned char)byte[2];
	return (ret_color);
}

/*
 *	***** ft_color_to_int *****
 *
 *	DESCRIPTION:
 *		Converts a t_rgb struct containing RGB values to an integer passable
 *		to mlx_pixel_put.
 *	RETURN:
 *		Returns an int representation of color.
 */

int	ft_color_to_int(t_rgb color)
{
	int		ret;
	char	*byte;

	ret = 0;
	byte = (char *)&ret;
	byte[0] = (unsigned char)(color.blue);
	byte[1] = (unsigned char)(color.green);
	byte[2] = (unsigned char)(color.red);
	byte[3] = 1;
	return (ret);
}
