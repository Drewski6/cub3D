/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 14:22:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include "debug.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "map_parsing.h"

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
	(void) map_data;
	(void) fd;
	return (0);
}

/*
**	NAME
		ft_init_map
**	DESCRIPTION
		1. test and try to open the file from argv[1] open read
		2. 
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
		return (1);
	close(fd);
	return (0);
}
