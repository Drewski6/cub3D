/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:29:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 16:18:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3ddef.h"
#include "images.h"
#include "engine.h"
#include "libft.h"
#include "map_parsing.h"

int	ft_tex_init(t_engine *engine, t_map_data *map_data, t_ray *ray, t_tex *tex)
{
	int	vert_bar_height;

	tex->image = ft_select_texture(engine, ray);
	tex->y_offset = 0;
	vert_bar_height = (map_data->bs * WIN_X) / ray->dist_from_player;
	tex->y_step = (double)tex->image->size.y / (double)vert_bar_height;
	if (vert_bar_height > WIN_Y)
	{
		tex->y_offset = ((double)vert_bar_height - (double)WIN_Y) / 2;
		vert_bar_height = WIN_Y;
	}
	tex->y = tex->y_offset * tex->y_step;
	if (ray->d_wall == D_NORTH || ray->d_wall == D_SOUTH)
		tex->x = (int)(ray->coord_x / ((double)map_data->bs
					/ tex->image->size.x)) % tex->image->size.x;
	if (ray->d_wall == D_WEST || ray->d_wall == D_EAST)
		tex->x = (int)(ray->coord_y / ((double)map_data->bs
					/ tex->image->size.x)) % tex->image->size.x;
	return (vert_bar_height);
}

/*
 *	***** ft_select_texture *****
 *
 *	DESCRIPTION:
 *		Basic switch for selecting the correct texture to draw.
 *	RETURN:
 *		Returns pointer to correct texture.
 */

t_image	*ft_select_texture(t_engine *engine, t_ray *ray)
{
	t_image	*texture;

	if (ray->d_wall == D_NORTH)
		texture = ft_get_image(engine->lst_images, NT);
	if (ray->d_wall == D_SOUTH)
		texture = ft_get_image(engine->lst_images, ST);
	if (ray->d_wall == D_EAST)
		texture = ft_get_image(engine->lst_images, ET);
	if (ray->d_wall == D_WEST)
		texture = ft_get_image(engine->lst_images, WT);
	return (texture);
}
