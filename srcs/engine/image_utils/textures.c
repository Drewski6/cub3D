/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 07:50:07 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 08:03:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "map_parsing.h"
#include "mlx.h"
#include <stdio.h>

bool	ft_load_textures(t_engine *engine, t_map_data *map_data)
{
	(void) engine;
	(void) map_data;
	printf("North Texture: %s\n", map_data->no);
	printf("South Texture: %s\n", map_data->so);
	printf("East Texture: %s\n", map_data->ea);
	printf("West Texture: %s\n", map_data->we);
	return (0);
}
