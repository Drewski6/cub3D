/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:59:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/07 18:51:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3ddef.h"
#include "libft.h"
#include "gnl.h"
#include <stdio.h>
#include <errno.h>
#include "map_parsing.h"
#include "engine.h"
#include <stdlib.h>

bool	ft_initial_read_in(t_list **list, int fd, char **line)
{
	t_list	*current;

	*list = ft_lstnew((void *)*line);
	if (errno != 0)
		return (perror("malloc"), 1);
	while (*line)
	{
		*line = get_next_line(fd);
		if (errno != 0)
			return (perror("malloc"), 1);
		ft_striteri(*line, ft_newline_to_null);
		if (ft_strset(*line, "01NSEW "))
			return (ft_putstr_fd("Error\nInvalid character in map or \
elements out of order.\n", 2),
				1);
		current = ft_lstnew(*line);
		if (!current)
			return (perror("malloc"), 1);
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
		return (perror("malloc"), NULL);
	while (i < y_len + 2)
	{
		map[i] = (char *)ft_calloc(x_len + 1 + 2, sizeof(char));
		if (!map[i])
			return (perror("malloc"), NULL);
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

/*
	NAME
		ft_check_for_empty_lines
	DESCRIPTION
		Deletes all the lines in the linked list that have only \n or space.
	RETURN
		returns 0 because if statement
*/

bool	ft_check_for_empty_lines(t_list **lst)
{
	t_list	*current;
	t_list	*delete;

	current = *lst;
	while (current && current->next)
	{
		if ((char *)current->next->content
			&& ft_strset((char *)current->next->content, "\n ") == NULL)
		{
			delete = current->next;
			if (current->next)
				current->next = current->next->next;
			ft_lstdelone(delete, ft_lst_free_link);
		}
		else
			current = current->next;
	}
	return (0);
}

bool	ft_read_in_map(t_map_data *map_data, int fd, char **line)
{
	t_list	*lst_map;
	size_t	x_len;
	size_t	y_len;
	int		biggest;

	if (ft_initial_read_in(&lst_map, fd, line))
		return (ft_lstclear(&lst_map, ft_lst_free_link), 1);
	if (ft_check_for_empty_lines(&lst_map))
		return (ft_putstr_fd("Error\nneed to clean\n", 2), 1);
	x_len = ft_lst_largest(&lst_map, ft_lst_strlen);
	y_len = ft_lstsize(lst_map) - 1;
	map_data->size = (t_point){x_len, y_len};
	if (map_data->size.x > map_data->size.y)
		biggest = map_data->size.x;
	else
		biggest = map_data->size.y;
	if (biggest == 0)
		return (ft_putstr_fd("Error\nMap size is 0.\n", 2),
			ft_lstclear(&lst_map, ft_lst_free_link), 1);
	map_data->bs = MAP_SIZE / biggest;
	map_data->map = ft_create_blank_map(x_len, y_len);
	if (!map_data->map)
		return (ft_lstclear(&lst_map, ft_lst_free_link), 1);
	ft_xfer_map(lst_map, map_data->map);
	return (ft_lstclear(&lst_map, ft_lst_free_link), 0);
}
