/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/22 10:48:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include <stddef.h>
#include "debug.h"
#include "libft.h"
#include <stdio.h>
#include "ft_printf.h"

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
				return (*head = (t_coord){x, y, 7, 0},
					ft_get_coord_neighbors(head, map, '1'), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_unrotate_coord(t_coord *coord, int org_src)
{
	unsigned char	buf;

	buf = 0;
	while (coord->source < org_src)
	{
		buf = coord->neighbors & (1 << 7);
		coord->neighbors = coord->neighbors << 1;
		buf = buf >> 7;
		coord->neighbors = coord->neighbors | buf;
		coord->source++;
	}
	return (org_src);
}

int	ft_rotate_coord(t_coord *coord)
{
	unsigned char	buf;
	int				src_save;

	buf = 0;
	src_save = coord->source;
	while (coord->source != 0)
	{
		buf = coord->neighbors & (1 << 0);
		coord->neighbors = coord->neighbors >> 1;
		buf = buf << 7;
		coord->neighbors = coord->neighbors | buf;
		coord->source--;
	}
	return (src_save);
}

int	ft_find_next_step(t_coord *coord)
{
	int	i;

	i = 7;
	while (!(coord->neighbors & (1 << i)) && i != -1)
		i--;
	return (i);
}

int	ft_take_next_step(t_coord *head, char **map, int i)
{
	if (i == 7)
		return (head->x -= 1, head->y -= 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 6)
		return (head->x += 0, head->y -= 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 5)
		return (head->x += 1, head->y -= 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 4)
		return (head->x += 1, head->y += 0, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 3)
		return (head->x += 1, head->y += 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 2)
		return (head->x += 0, head->y += 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 1)
		return (head->x -= 1, head->y += 1, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	else if (i == 0)
		return (head->x -= 1, head->y += 0, head->source = (i + 4) % 8,
			ft_get_coord_neighbors(head, map, '1'), 0);
	return (0);
}

bool	ft_map_crawl(char **map, t_coord *head)
{
	t_coord	start;
	t_coord	next;
	int		i;
	int		buf;
	int		buf2;

	i = 0;
	ft_memcpy(&start, head, sizeof(t_coord));
	ft_memcpy(&next, head, sizeof(t_coord));
	debug_print_coord_data(&start, "start");
	buf2 = ft_find_next_step(&next);
	ft_take_next_step(&next, map, buf2);
	debug_print_coord_data(&next, "next after first step");
	while ((next.x != start.x) || (next.y != start.y))
	{
		//debug_print_coord_data(&next, "next before rotate");
		buf = ft_rotate_coord(&next);
		//debug_print_coord_data(&next, "next after rotate before findstep");
		buf2 = ft_find_next_step(&next);
		//debug_print_coord_data(&next, "next after step before unrotate");
		ft_unrotate_coord(&next, buf);
		//debug_print_coord_data(&next, "next after unrotate before takestep");
		ft_take_next_step(&next, map, (buf2 + next.source) % 8);
		debug_print_coord_data(&next, "next after takestep");
		ft_memcpy(head, &next, sizeof(t_coord));
		i++;
		ft_printf("i: %d\n", i);
		ft_printf("******************************************\n");
	}
	printf("i: %d\n", i);
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
	return (0);
}
