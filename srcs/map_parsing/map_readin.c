/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:59:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 16:59:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdbool.h>
#include "ft_printf.h"

bool	ft_read_in_map(t_map_data *map_data, int fd, char **line)
{
	(void) map_data;
	(void) fd;
	(void) line;
	ft_printf("map line: %s\n", *line);
	return (0);
}
