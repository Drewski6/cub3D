/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2023/11/18 12:51:14 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 13:29:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "debug.h"
#include "ft_printf.h"

void	debug_print_table(char **table)
{
	int	i;

	i = 0;
	if (table)
	{
		ft_printf("\n");
		while (table[i])
			ft_printf("%s\n", table[i++]);
	}
	else
	{
		ft_printf("(NULL)\n");
	}
}

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
	ft_printf("map: ");
	if (map_data->map)
		debug_print_table(map_data->map);
	else
		ft_printf("(NULL)\n");
}
