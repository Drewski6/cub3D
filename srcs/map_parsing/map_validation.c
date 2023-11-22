/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/22 14:55:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"
#include "cub3D.h"
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"

bool	ft_map_boarder_check(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (y == 1 || y == (int)(ft_tablen(map) - 2))
			if (ft_strset(map[y], " 1"))
				return (ft_putstr_fd(
						"Error: Map boarder contains invalid character.\n"
						, 2), 1);
		if (map[y][1] != '1' && map[y][1] != ' ')
			return (ft_putstr_fd(
					"Error: Map boarder contains invalid character.\n"
					, 2), 1);
		if (map[y][ft_strlen(map[y]) - 2] != '1'
			&& map[y][ft_strlen(map[y]) - 2] != ' ')
			return (ft_putstr_fd(
					"Error: Map boarder contains invalid character.\n"
					, 2), 1);
		y++;
	}
	return (0);
}

bool	ft_map_space_invalid_neighbors(char **map, t_coord *coord)
{
	ft_get_coord_neighbors(coord, map, '0');
	if (coord->neighbors)
		return (1);
	ft_get_coord_neighbors(coord, map, 'N');
	if (coord->neighbors)
		return (1);
	ft_get_coord_neighbors(coord, map, 'S');
	if (coord->neighbors)
		return (1);
	ft_get_coord_neighbors(coord, map, 'E');
	if (coord->neighbors)
		return (1);
	ft_get_coord_neighbors(coord, map, 'W');
	if (coord->neighbors)
		return (1);
	return (0);
}

bool	ft_map_space_check(char **map)
{
	t_coord	coord;
	int		y;
	int		x;

	y = 1;
	while (map[y] && map[y + 1])
	{
		x = 1;
		while (map[y][x] && map[y][x + 1])
		{
			if (map[y][x] == ' ')
			{
				coord = (t_coord){x, y, 0, 0};
				if (ft_map_space_invalid_neighbors(map, &coord))
					return (ft_printf(
							"Error: invalid character at x(%d) y(%d).\n",
							x + 1, y - 1), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
 *	***** ft_map_validation *****
 *
 *	DESCRIPTION:
 *		Entry for map validation functions.
 *	NOTES:
 *		To verify the map, we will find the top left corner and crawl around
 *		the map to make sure all of its walls are 1's and they rejoin with 
 *		the starting spot.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_validation(t_map_data *map_data)
{
	t_coord	head;

	head = (t_coord){0, 0, 0, 0};
	if (0
		|| ft_map_crawl_get_start(map_data->map, &head)
		|| ft_map_crawl(map_data->map, &head)
		|| ft_map_boarder_check(map_data->map)
		|| ft_map_space_check(map_data->map)
	)
		return (ft_putstr_fd("Error: Map validation failed. Please check map.\n"
				, 2), 1);
	return (0);
}
