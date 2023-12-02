/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:29:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 11:19:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3ddef.h"
#include "images.h"
#include "engine.h"
#include "libft.h"

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
	{
		texture = ft_get_image(engine->lst_images, NT);
	}
	if (ray->d_wall == D_SOUTH)
		texture = ft_get_image(engine->lst_images, ST);
	if (ray->d_wall == D_EAST)
		texture = ft_get_image(engine->lst_images, ET);
	if (ray->d_wall == D_WEST)
		texture = ft_get_image(engine->lst_images, WT);
	return (texture);
}
