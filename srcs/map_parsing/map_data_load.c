/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:21:02 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 13:34:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "debug.h"
#include "libft.h"
#include "map_parsing.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/*
 *	***** ft_free_map_data *****
 *
 *	DESCRIPTION:
 *		Takes the struct map_data and frees all the elements and resets 
 *		everything to NULL.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_free_map_data(t_map_data *map_data)
{
	if (map_data->no)
	{
		free(map_data->no);
		map_data->no = NULL;
	}
	if (map_data->so)
	{
		free(map_data->so);
		map_data->so = NULL;
	}
	if (map_data->ea)
	{
		free(map_data->ea);
		map_data->ea = NULL;
	}
	if (map_data->we)
	{
		free(map_data->we);
		map_data->we = NULL;
	}
	if (map_data->map)
		ft_free_table(map_data->map);
	return ;
}

/*
 *	***** ft_read_in_map_data *****
 *
 *	DESCRIPTION:
 *		Separates the element parsing and the map parsing into 2 sections.
 *		Shares a pointer to line between the two so that when element parsing
 *		is finished, the most recently read line can be passed to the map parsing.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_read_in_map_data(t_map_data *map_data, int fd)
{
	char	*line;

	line = NULL;
	map_data->f = (t_rgb){-1, -1, -1};
	map_data->c = (t_rgb){-1, -1, -1};
	if (0
		|| ft_read_in_elements(map_data, fd, &line)
		|| ft_read_in_map(map_data, fd, &line)
	)
		return (free(line), line = NULL, 1);
	return (free(line), line = NULL, 0);
}

/*
 *	***** ft_map_data *****
 *
 *	DESCRIPTION:
 *		First opens the file indicated with filename and checks return.
 *		Second calls ft_read_in_map_data to read the file into the struct.
 *		Third validates map via ft_map_validation.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_map_data(t_map_data *map_data, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	if (0
		|| ft_read_in_map_data(map_data, fd)
		|| ft_map_data_validation(map_data)
		|| ft_map_validation(map_data)
	)
		return (close(fd), 1);
	return (close(fd), 0);
}
