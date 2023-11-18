/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 14:09:50 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include "args.h"
#include "map_parsing.h"

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
		|| ft_init_map(&map_data, argv[1])
	)
		return (1);
	return (0);
}
