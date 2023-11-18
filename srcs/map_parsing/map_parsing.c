/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 17:10:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include "debug.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "gnl.h"
#include "libft.h"
#include "map_parsing.h"
#include <string.h>
#include "ft_printf.h"

bool	ft_save_element(char **dest, char *src)
{
	if (*dest)
		return (ft_putstr_fd("Error: Duplicate element in map.", 2), 1);
	*dest = ft_strdup(src);
	if (!*dest)
		return (perror("Error: malloc"), 1);
	ft_striteri(*dest, ft_newline_to_null);
	return (0);
}

bool	ft_select_element(t_map_data *map_data, char **tab)
{
	if (!ft_strncmp(tab[0], "NO", 3))
		if (ft_save_element(&map_data->no, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "SO", 3))
		if (ft_save_element(&map_data->so, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "EA", 3))
		if (ft_save_element(&map_data->ea, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "WE", 3))
		if (ft_save_element(&map_data->we, tab[1]))
			return (1);
	return (0);
}

bool	ft_read_in_elements(t_map_data *map_data, int fd, char **line)
{
	char	**tab;

	(void) map_data;
	*line = get_next_line(fd);
	if (!*line)
		return (1);
	while (*line)
	{
		if (**line != '\n')
		{
			tab = ft_split(*line, ' ');
			if (!tab)
				return (perror("Error: malloc"), 1);
			if (ft_select_element(map_data, tab))
				return (ft_table_free(tab), 1);
			ft_table_free(tab);
		}
		free(*line);
		*line = NULL;
		*line = get_next_line(fd);
	}
	return (0);
}

/*
**	NAME
		ft_read_in_map_data
**	DESCRIPTION
		desc
**	RETURN
		Bool function returns 0 on success or 1 on error;
*/

bool	ft_read_in_map_data(t_map_data *map_data, int fd)
{
	char	*line;

	line = NULL;
	if (0
		|| ft_read_in_elements(map_data, fd, &line)
		|| ft_read_in_map(map_data, fd, &line)
	)
		return (free(line), 1);
	return (free(line), 0);
}

/*
**	NAME
		ft_init_map
**	DESCRIPTION
		First opens the file indicated with filename and checks return.
		Second calls ft_read_in_map_data to read the file into the struct.
		Third validates map via ft_map_validation.
**	RETURN
		Bool function returns 0 on success and 1 on error.
*/

bool	ft_init_map(t_map_data *map_data, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: open");
		return (1);
	}
	if (0
		|| ft_read_in_map_data(map_data, fd)
		|| ft_map_validation(map_data)
	)
	{
		debug_print_map_data(map_data);
		return (close(fd), 1);
	}
	debug_print_map_data(map_data);
	return (close(fd), 0);
}
