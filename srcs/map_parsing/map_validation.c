/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/22 13:44:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"
#include "cub3D.h"
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

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
