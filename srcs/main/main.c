/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 15:03:52 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "cub3D.h"
#include "debug.h"
#include "engine.h"
#include "ft_printf.h"
#include "libft.h"
#include "map_parsing.h"
#include "mlx.h"
#include <stdlib.h>
#include "keys.h"

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
	t_player	player;
	t_clear		clear;

	ft_bzero((void *)&map_data, sizeof(map_data));
	ft_bzero((void *)&engine, sizeof(engine));
	ft_bzero((void *)&player, sizeof(player));
	clear = (t_clear){(void *)&engine, (void *)&map_data, (void *)&player};
	if (0
		|| ft_arg_parse(argc, argv)
		|| ft_map_data(&map_data, argv[1])
		|| ft_engine_init(&engine)
		|| ft_player_init(&player, &map_data)
		|| ft_prerender(&engine, &map_data)
	)
		return (ft_free_map_data(&map_data), ft_free_engine(&engine), 1);
	if (ft_hooks_cub3d(&clear))
		return (ft_free_map_data(&map_data), ft_free_engine(&engine), 1);
	ft_render(&clear);
	debug_print_map_data(&map_data);
	mlx_loop(engine.mlx_ptr);
	return (ft_free_map_data(&map_data), ft_free_engine(&engine), 0);
}
