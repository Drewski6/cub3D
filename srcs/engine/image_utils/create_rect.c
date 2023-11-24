/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:17:28 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 13:48:29 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <stdio.h>

bool	ft_create_rect_image(t_engine *engine, t_image_id ID, t_rect rect)
{
	t_image	*image;
	t_point	size;

	size.x = rect.bottom_right.x - rect.top_left.x;
	size.y = rect.bottom_right.y - rect.top_left.y;
	printf("size: x(%f) y(%f)\n", size.x, size.y);
	if (ft_add_image(&engine->lst_images, engine->mlx_ptr, ID, size))
		return (1);
	image = ft_get_image(engine->lst_images, ID);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during prerender.\n", 2), 1);
	ft_paint_bucket(image, rect);
	return (0);
}
