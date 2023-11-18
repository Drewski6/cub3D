/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 23:52:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "debug.h"
#include "errno.h"
#include "ft_printf.h"
#include "gnl.h"
#include "libft.h"
#include "map_parsing.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

bool	ft_save_texture_path(char **dest, char *src)
{
	if (*dest)
		return (ft_putstr_fd("Error: Duplicate element in map.", 2), 1);
	*dest = ft_strdup(src);
	if (!*dest)
		return (perror("Error: malloc"), 1);
	return (0);
}

bool	ft_save_rgb_settings(t_rgb *rgb, char *src)
{
	char	**tab;

	tab = ft_split(src, ',');
	if (!tab)
		return (perror("Error: malloc"), 1);
	if (ft_tablen(tab) != 3)
		return (ft_free_table(tab),
			ft_putstr_fd("Error: RGB values incorrect\n", 2), 1);
	if (!ft_tabiter_ver(tab, ft_striter_ver, ft_isdigit))
		return (ft_free_table(tab),
			ft_putstr_fd("Error: RGB values incorrect\n", 2), 1);
	rgb->red = ft_atoi(tab[0]);
	rgb->green = ft_atoi(tab[1]);
	rgb->blue = ft_atoi(tab[2]);
	return (ft_free_table(tab), 0);
}

/*
 *	***** ft_select_element *****
 *
 *	DESCRIPTION:
 *		Reads the first item in the tab to select which function to use to 
 *		pack the data into the map_data struct.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_select_element(t_map_data *map_data, char **tab)
{
	int	ret;

	ret = 0;
	if (ft_tablen(tab) != 2)
		ret = 2;
	else if (!ft_strncmp(tab[0], "NO", 3))
		ret = ft_save_texture_path(&map_data->no, tab[1]);
	else if (!ft_strncmp(tab[0], "SO", 3))
		ret = ft_save_texture_path(&map_data->so, tab[1]);
	else if (!ft_strncmp(tab[0], "EA", 3))
		ret = ft_save_texture_path(&map_data->ea, tab[1]);
	else if (!ft_strncmp(tab[0], "WE", 3))
		ret = ft_save_texture_path(&map_data->we, tab[1]);
	else if (!ft_strncmp(tab[0], "F", 2))
		ret = ft_save_rgb_settings(&map_data->f, tab[1]);
	else if (!ft_strncmp(tab[0], "C", 2))
		ret = ft_save_rgb_settings(&map_data->c, tab[1]);
	else
		ret = 1;
	if (ret == 1)
		return (1);
	else if (ret == 2)
		return (ft_putstr_fd("Error: Invalid line in map file\n", 2), 1);
	return (ret);
}

bool	ft_read_in_elements(t_map_data *map_data, int fd, char **line)
{
	char	**tab;

	*line = get_next_line(fd);
	if (errno != 0)
		return (ft_putstr_fd("Error: malloc", 2), 1);
	while (*line)
	{
		if (**line != '\n')
		{
			ft_striteri(*line, ft_newline_to_null);
			if (ft_strset(*line, "01NSWE ") == NULL)
				return (0);
			tab = ft_split(*line, ' ');
			if (!tab)
				return (perror("Error: malloc"), 1);
			if (ft_select_element(map_data, tab))
				return (ft_free_table(tab), 1);
			ft_free_table(tab);
		}
		free(*line);
		*line = NULL;
		*line = get_next_line(fd);
	}
	return (0);
}
