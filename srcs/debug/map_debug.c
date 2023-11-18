/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:14 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 13:19:13 by dpentlan         ###   ########.fr       */
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
	if (map_data->NO)
		ft_printf("NO: %s\n", map_data->NO);
	else
		ft_printf("NO: (NULL)\n");
	if (map_data->SO)
		ft_printf("SO: %s\n", map_data->SO);
	else
		ft_printf("SO: (NULL)\n");
	if (map_data->EA)
		ft_printf("EA: %s\n", map_data->EA);
	else
		ft_printf("EA: (NULL)\n");
	if (map_data->WE)
		ft_printf("WE: %s\n", map_data->WE);
	else
		ft_printf("WE: (NULL)\n");
	ft_printf("F: R(%d), G(%d), B(%d)\n",
		map_data->F.red, map_data->F.green, map_data->F.blue);
	ft_printf("C: R(%d), G(%d), B(%d)\n",
		map_data->C.red, map_data->C.green, map_data->C.blue);
	ft_printf("map: ");
	if (map_data->map)
		debug_print_table(map_data->map);
	else
		ft_printf("(NULL)\n");
}
