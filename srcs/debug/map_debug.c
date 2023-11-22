/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:41:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/22 10:45:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "debug.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

/*
 *	***** debug_print_map_data *****
 *
 *	DESCRIPTION:
 *		Used to print the contents and current values of the map_data struct.
 *	RETURN:
 *		Void function does not return a value.
 */

void	debug_print_map_data(t_map_data *map_data)
{
	if (map_data->no)
		ft_printf("no: %s\n", map_data->no);
	else
		ft_printf("no: (NULL)\n");
	if (map_data->so)
		ft_printf("so: %s\n", map_data->so);
	else
		ft_printf("so: (NULL)\n");
	if (map_data->ea)
		ft_printf("ea: %s\n", map_data->ea);
	else
		ft_printf("ea: (NULL)\n");
	if (map_data->we)
		ft_printf("we: %s\n", map_data->we);
	else
		ft_printf("we: (NULL)\n");
	ft_printf("f: R(%d), G(%d), B(%d)\n",
		map_data->f.red, map_data->f.green, map_data->f.blue);
	ft_printf("c: R(%d), G(%d), B(%d)\n",
		map_data->c.red, map_data->c.green, map_data->c.blue);
	ft_printf("map: \n");
	if (map_data->map)
		ft_print_table(map_data->map, 0);
	else
		ft_printf("(NULL)\n");
}

bool	debug_print_coord_data(t_coord *coord, char *name)
{
	char	*buf;

	if (!name)
		return (1);
	ft_printf("%s:\t\tx(%d) y(%d) src(%d)\n",
		name, coord->x, coord->y, coord->source);
	buf = ft_num_to_bin(coord->neighbors, 8);
	if (!buf)
		return (1);
	ft_printf("neighbors:\t%c%c%c\n\t\t\t%c %c\n\t\t\t%c%c%c\n",
		buf[0], buf[1], buf[2],
		buf[7], buf[3],
		buf[6], buf[5], buf[4]);
	free(buf);
	return (0);
}
