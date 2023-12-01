/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image_with_rays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:16:42 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/01 11:18:03 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3D.h"
#include "libft.h"

int	ft_draw_wall(t_map_data *map_data, t_image *rays, t_ray *ray,
				t_point *wr_head)
{
	int		vert_bar_height;
	int		i;

	vert_bar_height = (map_data->bs * WIN_X) / ray->dist_from_player;
	if (vert_bar_height > WIN_Y)
		vert_bar_height = WIN_Y;
	i = 0;
	while (i < vert_bar_height)
	{
		ft_img_buf_set_px_color(rays, (ray->color), wr_head->x, wr_head->y);
		wr_head->y++;
		i++;
	}
	return (wr_head->y);
}

void	ft_draw_ceiling(t_map_data *map_data, t_image *rays,
					t_point *wr_head, int vert_bar_height)
{
	int		v_offset;

	v_offset = WIN_Y / 2 - (vert_bar_height / 2);
	if (v_offset > WIN_Y / 2)
		v_offset = WIN_Y / 2;
	while (wr_head->y < v_offset)
	{
		ft_img_buf_set_px_color(rays, map_data->f, wr_head->x, wr_head->y);
		wr_head->y++;
	}
	return ;
}

void	ft_draw_floor(t_map_data *map_data, t_image *rays, t_point *wr_head)
{
	while (wr_head->y < WIN_Y)
	{
		ft_img_buf_set_px_color(rays, map_data->c, wr_head->x, wr_head->y);
		wr_head->y++;
	}
	return ;
}

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
		ft_draw_one_ray(player, map_data, &ray, wr_head.x);
		vert_bar_height = (map_data->bs * WIN_X) / ray.dist_from_player;
		if (vert_bar_height > WIN_Y)
			vert_bar_height = WIN_Y;
		ft_draw_ceiling(map_data, rays, &wr_head, vert_bar_height);
		ft_draw_wall(map_data, rays, &ray, &wr_head);
		wr_head.x++;
		ft_draw_floor(map_data, rays, &wr_head);
	}
	return (0);
}
