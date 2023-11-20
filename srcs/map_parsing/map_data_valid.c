/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:42:52 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/20 19:02:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"
#include "cub3D.h"
#include "libft.h"

/*
 *	***** ft_rgb_check *****
 *
 *	DESCRIPTION:
 *		Checks if the values entered for rbg color values are valid (0 to 255)
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_rgb_check(t_rgb *rgb)
{
	if (rgb->red < 0 || rgb->red > 255)
		return (1);
	if (rgb->green < 0 || rgb->green > 255)
		return (1);
	if (rgb->blue < 0 || rgb->blue > 255)
		return (1);
	return (0);
}

/*
 *	***** ft_map_data_validation *****
 *
 *	DESCRIPTION:
 *		Entry for map data validation functions.
 *	NOTES:
 *		- If any element of map_data is left null, reason to fail.
 *		- Check to make sure that the ints used in rgb values are between 0 and 255
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_data_validation(t_map_data *map_data)
{
	if (0
		|| !map_data->no
		|| !map_data->so
		|| !map_data->ea
		|| !map_data->we
		|| !map_data->map
	)
		return (ft_putstr_fd("Error: At least one map element not set.\n", 2),
			1);
	if (0
		|| ft_rgb_check(&map_data->f)
		|| ft_rgb_check(&map_data->c)
	)
		return (ft_putstr_fd(
				"Error: RGB values in map out of range or not set.\n", 2), 1);
	return (0);
}
