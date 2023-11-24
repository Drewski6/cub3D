/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:20:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 12:40:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"

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
