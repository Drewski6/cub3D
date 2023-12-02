/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image_with_rays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:16:42 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 14:24:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "images.h"
#include "map_parsing.h"
#include "libft.h"

/*
 *	***** ft_draw_wall *****
 *
 *	DESCRIPTION:
 *		Draw the wall portion of the ray which is a function of the distance 
 *		of the wall from the player.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_draw_wall(t_engine *engine, t_map_data *map_data,
				t_image *rays, t_ray *ray, t_point *wr_head)
{
	int		vert_bar_height;
	int		i;
	t_image	*texture;
	int		tex_offset;
	int		rays_offset;
	double	texture_y_step;
	double	texture_y;
	double	texture_y_offset;
	double	texture_x;

	i = 0;
	texture = ft_select_texture(engine, ray);
	texture_y_offset = 0;
	vert_bar_height = (map_data->bs * WIN_X) / ray->dist_from_player;
	texture_y_step = (double)texture->size.y / (double)vert_bar_height;
	if (vert_bar_height > WIN_Y)
	{
		texture_y_offset = ((double)vert_bar_height - (double)WIN_Y) / 2;
		vert_bar_height = WIN_Y;
	}
	texture_y = texture_y_offset * texture_y_step;
	if (ray->d_wall == D_NORTH || ray->d_wall == D_SOUTH)
		texture_x = (int)(ray->coord_x
				/ ((double)map_data->bs / texture->size.x)) % texture->size.x;
	if (ray->d_wall == D_WEST || ray->d_wall == D_EAST)
		texture_x = (int)(ray->coord_y
				/ ((double)map_data->bs / texture->size.x)) % texture->size.x;
	while (i < vert_bar_height)
	{
		rays_offset = (wr_head->y * rays->size_line) + (wr_head->x * 4);
		tex_offset = ((int)texture_y * texture->size_line) + (texture_x * 4);
		rays->img_buf[rays_offset + 0] = texture->img_buf[tex_offset + 0];
		rays->img_buf[rays_offset + 1] = texture->img_buf[tex_offset + 1];
		rays->img_buf[rays_offset + 2] = texture->img_buf[tex_offset + 2];
		rays->img_buf[rays_offset + 3] = texture->img_buf[tex_offset + 3];
		wr_head->y++;
		texture_y += texture_y_step;
		i++;
	}
	return ;
}

/*
 *	***** ft_draw_ceiling *****
 *
 *	DESCRIPTION:
 *		Draws the ceiling which is determined by the vertical offset which
 *		depends on the vertical wall height.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_draw_ceiling(t_map_data *map_data, t_image *rays,
					t_point *wr_head, int vert_bar_height)
{
	int		v_offset;

	v_offset = WIN_Y / 2 - (vert_bar_height / 2);
	if (v_offset > WIN_Y / 2)
		v_offset = WIN_Y / 2;
	while (wr_head->y < v_offset)
	{
		ft_img_buf_set_px_color(rays, map_data->c, wr_head->x, wr_head->y);
		wr_head->y++;
	}
	return ;
}

/*
 *	***** ft_draw_floor *****
 *
 *	DESCRIPTION:
 *		Draws the floor portion of the column which is simply the rest of
 *		of the column to draw.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_draw_floor(t_map_data *map_data, t_image *rays, t_point *wr_head)
{
	while (wr_head->y < WIN_Y)
	{
		ft_img_buf_set_px_color(rays, map_data->f, wr_head->x, wr_head->y);
		wr_head->y++;
	}
	return ;
}

/*
 *	***** ft_draw_rays *****
 *
 *	DESCRIPTION:
 *		Draws a ray for each column in the window based on the distance of the 
 *		nearest wall from the player's camera.
 *		Draws these rays one at a time by first finding the distance,
 *		drawing the ceiling based on the distance, drawing the wall based on the 
 *		distance, and finally drawing the floor by filling in the rest.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 *		This function cannot fail but returns 0 so that it can be used in an if 
 *		statement for the render function.
 */

bool	ft_draw_rays(t_engine *engine, t_player *player, t_map_data *map_data)
{
	t_image	*rays;
	t_point	wr_head;
	int		vert_bar_height;
	t_ray	ray;

	rays = ft_get_image(engine->lst_images, RAYS);
	if (!rays)
		return (ft_putstr_fd("Error\nImage with matching ID not found.\n", 2), 1);
	wr_head.x = 0;
	ft_bzero(&ray, sizeof(t_ray));
	while (wr_head.x < WIN_X)
	{
		wr_head.y = 0;
		ft_get_ray_size(player, map_data, &ray, wr_head.x);
		vert_bar_height = (map_data->bs * WIN_X) / ray.dist_from_player;
		if (vert_bar_height > WIN_Y)
			vert_bar_height = WIN_Y;
		ft_draw_ceiling(map_data, rays, &wr_head, vert_bar_height);
		ft_draw_wall(engine, map_data, rays, &ray, &wr_head);
		wr_head.x++;
		ft_draw_floor(map_data, rays, &wr_head);
	}
	return (0);
}
