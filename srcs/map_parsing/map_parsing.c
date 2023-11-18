/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 14:08:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include "debug.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*
**	NAME
		ft_init_map
**	DESCRIPTION
		1. test and try to open the file from argv[1] open read
		2. 
**	RETURN
		Bool returns 0 for successful map load or 1 for error.
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
	close(fd);
	return (0);
}
