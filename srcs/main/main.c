/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 10:31:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cub3D.h"
#include "debug.h"
#include "libft.h"
#include "map_parsing.h"
#include <stdlib.h>
#include "engine.h"

/*
 * ***** main *****
 *
 *	ALLOWED FUNCTIONS:
 *			open, close, read, write, printf, malloc, free, perror, strerror, exit.
 *			All functions of the math library (-lm man man 3 math).
 *			All functions of the MinilibX.
 *	RETURN:
 *		Int returns 0 on success or non-0 int on error.
 */

int	main(int argc, char **argv)
{
	t_map_data	map_data;

	ft_bzero((void *)&map_data, sizeof(map_data));
	if (0
		|| ft_arg_parse(argc, argv)
		|| ft_map_data(&map_data, argv[1])
	)
	{
		debug_print_map_data(&map_data);
		return (ft_free_map_data(&map_data), 1);
	}
	ft_engine_init();
	debug_print_map_data(&map_data);
	return (ft_free_map_data(&map_data), 0);
}
