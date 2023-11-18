/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 18:26:14 by dpentlan         ###   ########.fr       */
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

bool	ft_save_texture_path(char **dest, char *src)
{
	if (*dest)
		return (ft_putstr_fd("Error: Duplicate element in map.", 2), 1);
	*dest = ft_strdup(src);
	if (!*dest)
		return (perror("Error: malloc"), 1);
	ft_striteri(*dest, ft_newline_to_null);
	return (0);
}

bool	ft_save_rgb_settings(t_rgb *rgb, char *src)
{
	char	**tab;

	(void) rgb;
	ft_striteri(src, ft_newline_to_null);
	tab = ft_split(src, ',');
	if (!tab)
		return (perror("Error: malloc"), 1);
	if (ft_tablen(tab) != 3)
		return (ft_table_free(tab),
			ft_putstr_fd("Error: RGB values incorrect\n", 2), 1);
	if (!ft_tabiter_ver(tab, ft_striter_ver, ft_isdigit))
		return (ft_table_free(tab),
			ft_putstr_fd("Error: RGB values incorrect\n", 2), 1);
	rgb->red = ft_atoi(tab[0]);
	rgb->green = ft_atoi(tab[1]);
	rgb->blue = ft_atoi(tab[2]);
	return (ft_table_free(tab), 0);
}

bool	ft_select_element(t_map_data *map_data, char **tab)
{
	if (!ft_strncmp(tab[0], "NO", 3))
		if (ft_save_texture_path(&map_data->no, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "SO", 3))
		if (ft_save_texture_path(&map_data->so, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "EA", 3))
		if (ft_save_texture_path(&map_data->ea, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "WE", 3))
		if (ft_save_texture_path(&map_data->we, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "F", 2))
		if (ft_save_rgb_settings(&map_data->f, tab[1]))
			return (1);
	if (!ft_strncmp(tab[0], "C", 2))
		if (ft_save_rgb_settings(&map_data->c, tab[1]))
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
			// if (*line contains only "01NSEW ")
			// 	were at the map and need to return early.
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
