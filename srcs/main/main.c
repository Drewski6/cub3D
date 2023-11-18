/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 12:56:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include "args.h"
#include "map_parsing.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;

	if (0
		|| ft_arg_parse(argc, argv)
		|| ft_init_map(&map_data, argv[1])
	)
		return (1);
	return (0);
}
