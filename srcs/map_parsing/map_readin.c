/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:59:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/19 21:24:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include "gnl.h"
#include "libft.h"
#include <stdio.h>


bool	ft_read_in_map(t_map_data *map_data, int fd, char **line)
{
	t_list	*current;

	map_data->map = ft_lstnew((void *)*line);
	while (*line)
	{
		*line = get_next_line(fd);
		current = ft_lstnew(*line);
		if (!current)
			return (perror("Error: malloc"), 1);
		ft_lstadd_back(&map_data->map, current);
	}
	return (0);
}
