/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:21:02 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 19:27:38 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include "libft.h"
#include "map_parsing.h"
#include "debug.h"

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
		return (free(line), line = NULL, 1);
	return (free(line), line = NULL, 0);
}

/*
**	NAME
		ft_map_data
**	DESCRIPTION
		First opens the file indicated with filename and checks return.
		Second calls ft_read_in_map_data to read the file into the struct.
		Third validates map via ft_map_validation.
**	RETURN
		Bool function returns 0 on success and 1 on error.
*/

bool	ft_map_data(t_map_data *map_data, char *filename)
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
