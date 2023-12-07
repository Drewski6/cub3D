/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/07 11:41:17 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"
#include "libft.h"

/*
 *	***** ft_map_boarder_check *****
 *
 *	DESCRIPTION:
 *		Check the boarder of the map and make sure everything is a '1' or ' '
 *		This is because I cant run ft_get_coord_neighbors on the outer boarder
 *		so to make sure that no spaces touch any unwanted characters I need This
 *		initial check.
 *			        
 *			 111111 
 *			 1    1 
 *			 111111 
 *			        
 *		Making sure all the '1's above are either '1' or space.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_boarder_check(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (y == 1 || y == (int)(ft_tablen(map) - 2))
			if (ft_strset(map[y], " 1"))
				return (ft_putstr_fd(
						"Error\nMap boarder contains invalid character.\n"
						, 2), 1);
		if (map[y][1] != '1' && map[y][1] != ' ')
			return (ft_putstr_fd(
					"Error\nMap boarder contains invalid character.\n"
					, 2), 1);
		if (map[y][ft_strlen(map[y]) - 2] != '1'
			&& map[y][ft_strlen(map[y]) - 2] != ' ')
			return (ft_putstr_fd(
					"Error\nMap boarder contains invalid character.\n"
					, 2), 1);
		y++;
	}
	return (0);
}

/*
 *	***** ft_map_space_invalid_neighbors *****
 *
 *	DESCRIPTION:
 *		Checks the neighbors of a coordinate for any invalid characters.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error (invalid ch found).
 */

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

/*
 *	***** ft_map_space_check *****
 *
 *	DESCRIPTION:
 *		Loop over the map and look at every space character and check its
 *		neighbors to see if they are next to an invalid character.
 *		Does not check outer space padding layer on map.
 *		that is why there are y + 1 and y = 1 etc.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

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
					return (ft_putstr_fd(
							"Error\nInvalid character next to a space.\n",
							2), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
 *	***** ft_map_at_least_one_start *****
 *
 *	DESCRIPTION:
 *		Loops over the map and checks to make sure there is at least one
 *		N, S, E, or W character.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_at_least_one_start(t_map_data *map_data)
{
	int		y;
	char	*nsew;
	int		found_one;

	y = 0;
	found_one = 0;
	while (map_data->map[y])
	{
		nsew = ft_strset(map_data->map[y], "01 ");
		if (nsew)
		{
			if (found_one == 1)
				return (ft_putstr_fd("Error\n\
More than one starting position found.\n", 2), 1);
			map_data->start_pos.x = nsew - map_data->map[y];
			map_data->start_pos.y = y;
			map_data->start_pos.source = 0;
			map_data->start_pos.neighbors = 0;
			map_data->start_ori = *nsew;
			found_one = 1;
		}
		y++;
	}
	if (found_one != 1)
		return (ft_putstr_fd("Error\n\
No starting position (N, S, E, or W) in map.\n", 2), 1);
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
		|| ft_map_at_least_one_start(map_data)
	)
		return (1);
	return (0);
}
