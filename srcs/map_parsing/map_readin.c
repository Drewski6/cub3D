/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:59:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/20 18:31:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include "gnl.h"
#include "libft.h"
#include <stdio.h>

bool	ft_initial_read_in(t_list **list, int fd, char **line)
{
	t_list	*current;

	*list = ft_lstnew((void *)*line);
	while (*line)
	{
		*line = get_next_line(fd);
		ft_striteri(*line, ft_newline_to_null);
		current = ft_lstnew(*line);
		if (!current)
			return (perror("Error: malloc"), 1);
		ft_lstadd_back(list, current);
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
	return (map);
}

void	ft_xfer_map(t_list *list, char **map)
{
	t_list	*current;
	size_t	i;
	size_t	y_len;

	i = 1;
	current = list;
	y_len = ft_lstsize(list) - 1;
	while (i <= y_len)
	{
		ft_memcpy((void *)&map[i][1], current->content,
			ft_strlen(current->content));
		current = current->next;
		i++;
	}
}

bool	ft_read_in_map(t_map_data *map_data, int fd, char **line)
{
	t_list	*lst_map;
	size_t	x_len;
	size_t	y_len;

	if (ft_initial_read_in(&lst_map, fd, line))
		return (1);
	x_len = ft_lst_largest(&lst_map, ft_lst_strlen);
	y_len = ft_lstsize(lst_map) - 1;
	map_data->map = ft_create_blank_map(x_len, y_len);
	if (!map_data->map)
		return (1);
	ft_xfer_map(lst_map, map_data->map);
	ft_lstclear(&lst_map, ft_lst_free_link);
	return (0);
}
