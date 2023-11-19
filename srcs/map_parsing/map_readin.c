/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:59:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/19 23:33:42 by dpentlan         ###   ########.fr       */
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

bool	ft_read_in_map(t_map_data *map_data, int fd, char **line)
{
	size_t	x_len;
	size_t	y_len;

	if (ft_initial_read_in(map_data, fd, line))
		return (1);
	x_len = ft_lst_largest(&map_data->map, ft_lst_strlen);
	y_len = ft_lstsize(map_data->map) - 1;
	printf("Size of map: x(%ld), y(%ld)\n", x_len, y_len);
	return (0);
}
