/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/17 18:44:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include "args.h"
#include "map_parsing.h"

int	main(int argc, char **argv)
{
	ft_arg_parse(argc, argv);
	ft_init_map();
	return (0);
}
