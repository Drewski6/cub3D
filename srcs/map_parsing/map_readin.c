/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:59:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/20 13:00:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include "gnl.h"
#include "libft.h"
#include <stdio.h>

bool	ft_initial_read_in(t_map_data *map_data, int fd, char **line)
{
	t_list	*current;

	map_data->map = ft_lstnew((void *)*line);
	while (*line)
	{
		*line = get_next_line(fd);
		ft_striteri(*line, ft_newline_to_null);
		current = ft_lstnew(*line);
		if (!current)
			return (perror("Error: malloc"), 1);
		ft_lstadd_back(&map_data->map, current);
	}
	return (0);
}

char	**ft_create_blank_map(size_t x_len, size_t y_len)
{
	char	**map;
	size_t	i;

	i = 0;
	map = (char **)ft_calloc(y_len + 1 + 2, sizeof(char *));
	if (!map)
		return (perror("Error: malloc"), NULL);
	while (i < y_len + 2)
	{
		map[i] = (char *)ft_calloc(x_len + 1 + 2, sizeof(char));
		if (!map[i])
			return (perror("Error: malloc"), NULL);
		ft_memset(map[i], 32, x_len + 2);
		i++;
	}
	ft_printf("init map:\n");
	ft_print_table(map, 0);
	return (map);
}

bool	ft_read_in_map(t_map_data *map_data, int fd, char **line)
{
	char	**map;
	size_t	x_len;
	size_t	y_len;

	if (ft_initial_read_in(map_data, fd, line))
		return (1);
	x_len = ft_lst_largest(&map_data->map, ft_lst_strlen);
	y_len = ft_lstsize(map_data->map) - 1;
	map = ft_create_blank_map(x_len, y_len);
	if (!map)
		return (1);
	printf("Size of map: x(%ld), y(%ld)\n", x_len, y_len);
	return (0);
}
