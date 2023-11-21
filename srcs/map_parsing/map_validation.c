/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/21 18:44:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"
#include <stdio.h>

/*
 *	***** ft_get_coord_neighbors *****
 *
 *	DESCRIPTION:
 *		Takes a coord and a map and will find the values of the neighboring
 *		cells and set the corresponding bit of an unsigned char to 1 if a '1'
 *		is present.
 *		Bits are associated with a location relative to the coord point.
 *			0, 1, 2
 *			7, C, 3
 *			6, 5, 4
 *		So a value of (40) means bit 3 (8) and 5 (32) are on indicting there 
 *		is a '1' in the cell to the right and below the current point.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_get_coord_neighbors(t_coord *coord, char **map, int c)
{
	unsigned char	neighbors;

	neighbors = 0;
	if (map[coord->x - 1][coord->y + 0] == c)
		neighbors = neighbors | (1 << 7);
	if (map[coord->x - 1][coord->y + 1] == c)
		neighbors = neighbors | (1 << 6);
	if (map[coord->x + 0][coord->y + 1] == c)
		neighbors = neighbors | (1 << 5);
	if (map[coord->x + 1][coord->y + 1] == c)
		neighbors = neighbors | (1 << 4);
	if (map[coord->x + 1][coord->y + 0] == c)
		neighbors = neighbors | (1 << 3);
	if (map[coord->x + 1][coord->y - 1] == c)
		neighbors = neighbors | (1 << 2);
	if (map[coord->x + 0][coord->y - 1] == c)
		neighbors = neighbors | (1 << 1);
	if (map[coord->x - 1][coord->y - 1] == c)
		neighbors = neighbors | (1 << 0);
	coord->neighbors = neighbors;
}

/*
 *	***** ft_map_crawl_get_start *****
 *
 *	DESCRIPTION:
 *		Starts looking through the map for the starting place. This should be 
 *		the first non space in the top left most portion of the map.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_crawl_get_start(char **map, t_coord *head)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isinset(map[i][j], "01NSEW"))
				return (*head = (t_coord){i, j, 7, 0},
					ft_get_coord_neighbors(head, map, '1'), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_rotate_coord(t_coord *head)
{
	unsigned char	buf;

	buf = 0;
	while (head->source != 7)
	{
		buf = head->neighbors & (1 << 7);
		head->neighbors = head->neighbors << 1;
		buf = buf >> 7;
		head->neighbors = head->neighbors | buf;
		head->source++;
	}
	(void) head;
}

int	ft_find_next_coord(t_coord *head, char **map)
{
	(void) head;
	(void) map;
	return (0);
}

bool	ft_map_crawl(char **map, t_coord *head)
{
	t_coord	start;
	t_coord	next;

	ft_memcpy(&start, head, sizeof(t_coord));
	ft_memcpy(&next, head, sizeof(t_coord));
	while ((next.x != start.x) && (next.y != start.y))
	{
		ft_rotate_coord(&next);
		ft_find_next_coord(&next, map);
		ft_memcpy(head, &next, sizeof(t_coord));
	}
	printf("start x(%d) y(%d) source(%d) neighbors(%d)\n",
		start.x, start.y, start.source, (int)start.neighbors);
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
	)
		return (ft_putstr_fd("Error: Map validation failed. Please check map.\n"
				, 2), 1);
	printf("head: x(%d) y(%d) source(%d) neighbors(%d)\n",
		head.x, head.y, head.source, (int)head.neighbors);
	return (0);
}
