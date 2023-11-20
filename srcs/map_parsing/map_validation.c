/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/20 22:06:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"
#include <stdio.h>

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
			{
				head->x = i;
				head->y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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

	if (0
		|| ft_map_crawl_get_start(map_data->map, &head)
	)
		return (1);
	printf("head: x(%d) y(%d)\n", head.x, head.y);
	return (0);
}
