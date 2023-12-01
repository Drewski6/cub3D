/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:17:28 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/01 15:10:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "images.h"
#include "libft.h"

/*
 *	***** ft_create_rect_image *****
 *
 *	DESCRIPTION:
 *		Uses ft_add_image to add a new malloced image struct with initialized
 *		values to a linked list of images.
 *		Uses ft_get_image to then get the address of the newly created image
 *		and calls the paintbucket function to fill with an initial color.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_create_rect_image(t_engine *engine, t_image_id ID,
						t_point size, t_rgb color)
{
	t_image	*image;

	if (ft_add_image(&engine->lst_images, engine->mlx_ptr, ID, size))
		return (1);
	image = ft_get_image(engine->lst_images, ID);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	ft_paint_bucket(image, (t_rect){(t_point){0, 0}, size, color});
	return (0);
}
