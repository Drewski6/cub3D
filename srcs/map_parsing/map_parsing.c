/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:30 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 13:25:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include "debug.h"

/*
**	NAME
		ft_init_map
**	DESCRIPTION
		1. test and try to open the file from argv[1] open read
		2. 
**	RETURN
		Bool returns 0 for successful map load or 1 for error.
*/

bool	ft_init_map(t_map_data *map_data, char *file_name)
{
	debug_print_map_data(map_data);
	(void) file_name;
	return (0);
}
