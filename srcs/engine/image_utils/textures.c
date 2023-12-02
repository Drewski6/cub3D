/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 07:50:07 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 09:00:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"
#include "images.h"
#include "engine.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

bool	ft_xpm_image_init(t_image *image,
				void *mlx_ptr, t_image_id ID, t_point size, char *filename)
{
	image->mlx_ptr = mlx_ptr;
	image->id = ID;
	image->size = size;
	image->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, &size.x, &size.y);
	if (!image->img_ptr)
		return (ft_putstr_fd("failed mlx_xpm\n", 2), 1);
	image->bits_per_pixel = 0;
	image->size_line = 0;
	image->endian = 0;
	image->img_buf = NULL;
	image->img_buf = mlx_get_data_addr(
			image->img_ptr,
			&image->bits_per_pixel,
			&image->size_line,
			&image->endian);
	if (!image->img_buf)
		return (1);
	return (0);
}

bool	ft_add_xpm_image(t_engine *engine, char *filename,
					t_image_id ID, t_point size)
{
	t_image	*new_image;
	t_list	*new_link;

	new_image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!new_image)
		return (perror("malloc"), 1);
	if (ft_xpm_image_init(new_image, engine->mlx_ptr, ID, size, filename))
		return (free(new_image), 1);
	new_link = ft_lstnew(new_image);
	if (!new_link)
		return (perror("malloc"), 1);
	ft_lstadd_back(&engine->lst_images, new_link);
	return (0);
}

bool	ft_load_textures(t_engine *engine, t_map_data *map_data)
{
	int		width;
	int		height;

	width = 100;
	height = 100;
	if (ft_add_xpm_image(engine, map_data->no, NT,
			(t_point){width, height}))
		return (ft_putstr_fd("Error\nCould not open north texture.\n", 2), 1);
	printf("North Texture: %s loaded!\n", map_data->no);
	if (ft_add_xpm_image(engine, map_data->so, ST,
			(t_point){width, height}))
		return (ft_putstr_fd("Error\nCould not open south texture.\n", 2), 1);
	printf("South Texture: %s loaded!\n", map_data->so);
	if (ft_add_xpm_image(engine, map_data->ea, ET,
			(t_point){width, height}))
		return (ft_putstr_fd("Error\nCould not open east texture.\n", 2), 1);
	printf("East Texture: %s loaded!\n", map_data->ea);
	if (ft_add_xpm_image(engine, map_data->we, WT,
			(t_point){width, height}))
		return (ft_putstr_fd("Error\nCould not open west texture.\n", 2), 1);
	printf("West Texture: %s loaded!\n", map_data->we);
	return (0);
}

