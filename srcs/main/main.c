/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 18:24:17 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include "args.h"
#include "map_parsing.h"

static void	ft_free_map_data(t_map_data *map_data)
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
		ft_table_free(map_data->map);
	return ;
}

/*
**	NAME
		name
**	DESCRIPTION
		ALLOWED FUNCTIONS:
			open, close, read, write, printf, malloc, free, perror, strerror, exit
			All functions of the math library (-lm man man 3 math)
			All functions of the MinilibX
**	RETURN
		Int returns 0 on success or non-0 int on error.
*/

int	main(int argc, char **argv)
{
	t_map_data	map_data;

	ft_bzero((void *)&map_data, sizeof(map_data));
	if (0
		|| ft_arg_parse(argc, argv)
		|| ft_map_data(&map_data, argv[1])
	)
		return (ft_free_map_data(&map_data), 1);
	return (ft_free_map_data(&map_data), 0);
}
