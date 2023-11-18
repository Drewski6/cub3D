/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 14:44:59 by dpentlan         ###   ########.fr       */
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

bool	ft_process_line(t_map_data *map_data, char *line)
{
	static int	i;

	(void) map_data;
	printf("%02d: %s", i++, line);
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

	line = get_next_line(fd);
	if (!line)
		return (perror("Error: gnl"), 1);
	while (line)
	{
		if (ft_process_line(map_data, line))
			return (free(line), line = NULL,
				ft_putstr_fd("Error: error processing map file.\n", 2), 1);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (0);
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

	debug_print_map_data(map_data);
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
		return (close(fd), 1);
	return (close(fd), 0);
}
