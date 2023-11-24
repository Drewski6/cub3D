/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_or_send_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:20:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 12:55:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include "mlx.h"

/*
 *	***** ft_get_image *****
 *
 *	DESCRIPTION:
 *		Looks through a list containing images and checks the ID of the image.
 *		If a match is found with the argument ID, the address of the image is 
 *		returned.
 *	RETURN:
 *		Returns the address of the first image contained in the list that has
 *		a matching ID as the one provided as an argument.
 */

t_image	*ft_get_image(t_list *lst, t_image_id ID)
{
	t_list	*current;
	t_image	*image;

	current = lst;
	while (current)
	{
		image = (t_image *)current->content;
		if (image->id == ID)
			return (image);
		current = current->next;
	}
	return (NULL);
}

/*
 *	***** ft_send_image_to_window *****
 *
 *	DESCRIPTION:
 *		Uses ft_get_image to look for an image in list lst by ID and then send
 *		that image to the window.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_send_image_to_window(t_engine *engine, t_list *lst, t_image_id ID)
{
	t_image	*image;

	image = ft_get_image(lst, ID);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during render.\n", 2), 1);
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		image->img_ptr, 0, 0);
	return (0);
}
