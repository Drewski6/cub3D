/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 13:30:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cub3D.h"
#include "debug.h"
#include "engine.h"
#include "libft.h"
#include "map_parsing.h"
#include <stdlib.h>
#include "mlx.h"
#include "ft_printf.h"

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
	t_engine	engine;
	t_clear		clear;

	ft_bzero((void *)&map_data, sizeof(map_data));
	ft_bzero((void *)&engine, sizeof(engine));
	clear = (t_clear){(void *)&engine, (void *)&map_data};
	if (0
		|| ft_arg_parse(argc, argv)
		|| ft_map_data(&map_data, argv[1])
		|| ft_engine_init(&engine)
	)
		return (ft_free_map_data(&map_data), ft_free_engine(&engine), 1);
	if (0
		|| !mlx_hook(engine.win_ptr, 17, 0, &ft_close_cub3d, (void *)&clear)
		|| !mlx_key_hook(engine.win_ptr, &ft_key_press, (void *)&clear)
	)
		return (ft_putstr_fd(("Error\nmlx hook functions returned error.\n"), 2),
			ft_free_map_data(&map_data), ft_free_engine(&engine), 1);
	debug_print_map_data(&map_data);
	mlx_loop(engine.mlx_ptr);
	return (ft_free_map_data(&map_data), ft_free_engine(&engine), 0);
}
