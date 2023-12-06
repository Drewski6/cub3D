/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:29:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/06 13:13:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3ddef.h"
#include "images.h"
#include "engine.h"
#include "libft.h"
#include "map_parsing.h"
#include "math.h"

/*
 *	***** ft_tex_init *****
 *
 *	DESCRIPTION:
 *		Initialize the tex struct which will be used when indexing the 
 *		texture for values to push to the image.
 *	RETURN:
 *		Returns a newly calculated vertical bar height which has been
 *		capped at WIN_Y AFTER calculating the y texture offset.
 */

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
		tex->x = (int)(fabs(ray->coord_x)
				/ ((double)map_data->bs / tex->image->size.x))
			% tex->image->size.x;
	if (ray->d_wall == D_WEST || ray->d_wall == D_EAST)
		tex->x = (int)(fabs(ray->coord_y)
				/ ((double)map_data->bs / tex->image->size.x))
			% (tex->image->size.x);
	tex->x += 226;
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

/*
 *	***** ft_draw_wall *****
 *
 *	DESCRIPTION:
 *		Draw the wall portion of the ray which is a function of the distance 
 *		of the wall from the player.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_draw_wall(t_image *rays, t_point *wr_head, t_tex *tex,
				int vert_bar_height)
{
	int			i;
	int			rays_offset;

	i = 0;
	while (i < vert_bar_height)
	{
		rays_offset = (wr_head->y * rays->size_line) + (wr_head->x * 4);
		tex->tex_offset = ((int)tex->y * tex->image->size_line) + (tex->x * 4);
		rays->img_buf[rays_offset + 0]
			= tex->image->img_buf[tex->tex_offset + 0];
		rays->img_buf[rays_offset + 1]
			= tex->image->img_buf[tex->tex_offset + 1];
		rays->img_buf[rays_offset + 2]
			= tex->image->img_buf[tex->tex_offset + 2];
		rays->img_buf[rays_offset + 3]
			= tex->image->img_buf[tex->tex_offset + 3];
		wr_head->y++;
		tex->y += tex->y_step;
		i++;
	}
	return ;
}
