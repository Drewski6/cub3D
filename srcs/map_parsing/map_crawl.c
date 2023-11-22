/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_crawl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:17:14 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/22 15:24:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include <stddef.h>
#include "debug.h"
#include "libft.h"
#include <stdio.h>
#include "ft_printf.h"
#include "map_parsing.h"

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
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isinset(map[y][x], "01NSEW"))
				return (*head = (t_coord){x, y, 0, 0},
					ft_get_coord_neighbors(head, map, '1'), 0);
			x++;
		}
		y++;
	}
	return (ft_putstr_fd("Error: could not find start of map.\n", 2),
		1);
}

/*
 *	***** ft_get_coord_neighbors *****
 *
 *	DESCRIPTION:
 *		Takes a coord and a map and will find the values of the neighboring
 *		cells and set the corresponding bit of an unsigned char to 1 if a '1'
 *		is present.
 *		Bits are associated with a location relative to the coord point.
 *			7, 6, 5
 *			0, C, 4
 *			1, 2, 3
 *		So a value of (40) means bit 3 (8) and 5 (32) are on indicting there 
 *		is a '1' in the cell to the right and below the current point.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_get_coord_neighbors(t_coord *coord, char **map, int c)
{
	unsigned char	neighbors;

	neighbors = 0;
	if (map[coord->y + 0][coord->x - 1] == c)
		neighbors = neighbors | (1 << 0);
	if (map[coord->y + 1][coord->x - 1] == c)
		neighbors = neighbors | (1 << 1);
	if (map[coord->y + 1][coord->x + 0] == c)
		neighbors = neighbors | (1 << 2);
	if (map[coord->y + 1][coord->x + 1] == c)
		neighbors = neighbors | (1 << 3);
	if (map[coord->y + 0][coord->x + 1] == c)
		neighbors = neighbors | (1 << 4);
	if (map[coord->y - 1][coord->x + 1] == c)
		neighbors = neighbors | (1 << 5);
	if (map[coord->y - 1][coord->x + 0] == c)
		neighbors = neighbors | (1 << 6);
	if (map[coord->y - 1][coord->x - 1] == c)
		neighbors = neighbors | (1 << 7);
	coord->neighbors = neighbors;
}

/*
 *	***** ft_find_next_step *****
 *
 *	DESCRIPTION:
 *		Manipulates the neighbors value using bit masks to find the outside edge
 *		of the map and find where the next step should go.
 *		First while loop orients the outside edge to the left middle (location 0).
 *			7, 6, 5
 *			0, C, 4
 *			1, 2, 3
 *		Second while loop looks along the outside (starting at 7) and looks for
 *		the first wall (1 value).
 *		Third while loop undoes the rotation from the first While loop.
 *	RETURN:
 *		Return integer is the number of steps from the wall needed to take to 
 *		find the next wall. this is used in the ft_take_next_step function to 
 *		move the coord HEAD.
 */

int	ft_find_next_step(t_coord *coord)
{
	unsigned char	buf;
	int				src_cpy;
	int				i;

	src_cpy = coord->source;
	while (src_cpy != 0)
	{
		buf = coord->neighbors & (1 << 0);
		coord->neighbors = coord->neighbors >> 1;
		buf = buf << 7;
		coord->neighbors = coord->neighbors | buf;
		src_cpy--;
	}
	i = 7;
	while (!(coord->neighbors & (1 << i)) && i != -1)
		i--;
	while (src_cpy < coord->source)
	{
		buf = coord->neighbors & (1 << 7);
		coord->neighbors = coord->neighbors << 1;
		buf = buf >> 7;
		coord->neighbors = coord->neighbors | buf;
		src_cpy++;
	}
	return (i);
}

/*
 *	***** ft_take_next_step *****
 *
 *	DESCRIPTION:
 *		Takes int i and adjusts the head's x, y, and source value accordingly.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_take_next_step(t_coord *head, char **map, int i)
{
	if (i == 7)
		return (head->x -= 1, head->y -= 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 6)
		return (head->x += 0, head->y -= 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 5)
		return (head->x += 1, head->y -= 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 4)
		return (head->x += 1, head->y += 0, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 3)
		return (head->x += 1, head->y += 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 2)
		return (head->x += 0, head->y += 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 1)
		return (head->x -= 1, head->y += 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
	else if (i == 0)
		return (head->x -= 1, head->y += 0, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'));
}

/*
 *	***** ft_map_crawl *****
 *
 *	DESCRIPTION:
 *		Uses 3 coordinate structs (a read head, a starting position, and the 
 *		next coordinate position) to find the top left corner of the map and then
 *		walk the outside of the map to find its perimeter. 
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_crawl(char **map, t_coord *head)
{
	t_coord	start;
	t_coord	next;
	int		i;

	i = 0;
	if (head->neighbors == 0)
		return (ft_putstr_fd("Error: map perimeter too small.\n", 2), 1);
	ft_memcpy(&start, head, sizeof(t_coord));
	if (map[start.x][start.y] != '1')
		return (ft_putstr_fd("Error: invalid character in boarder.\n", 2), 1);
	ft_memcpy(&next, head, sizeof(t_coord));
	ft_take_next_step(&next, map, ft_find_next_step(&next));
	while ((next.x != start.x) || (next.y != start.y))
	{
		ft_take_next_step(&next, map,
			(ft_find_next_step(&next) + next.source) % 8);
		ft_memcpy(head, &next, sizeof(t_coord));
		i++;
	}
	if (i < 7)
		return (ft_putstr_fd("Error: map perimeter too small.\n", 2), 1);
	return (0);
}
