/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:33:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 08:55:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "images.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *	***** ft_image_init *****
 *
 *	DESCRIPTION:
 *		Initializes the image to be used in cub3D
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_image_init(t_image *image,
				void *mlx_ptr, t_image_id ID, t_point size)
{
	image->mlx_ptr = mlx_ptr;
	image->id = ID;
	image->size = size;
	image->img_ptr = mlx_new_image(mlx_ptr,
			size.x, size.y);
	if (!image->img_ptr)
		return (ft_putstr_fd("Error\nCould not initialize image.\n", 2), 1);
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
		return (ft_putstr_fd("Error\nCould not initialize image.\n", 2), 1);
	return (0);
}

/*
 *	***** ft_add_image *****
 *
 *	DESCRIPTION:
 *		Initializes a new image, and a new link for the linked list and adds
 *		a link pointing to the new image to the end of the list.
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_add_image(t_list **lst, void *mlx_ptr, t_image_id ID, t_point size)
{
	t_image	*new_image;
	t_list	*new_link;

	new_image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!new_image)
		return (perror("malloc"), 1);
	if (ft_image_init(new_image, mlx_ptr, ID, size))
		return (free(new_image), 1);
	new_link = ft_lstnew(new_image);
	if (!new_link)
		return (perror("malloc"), 1);
	ft_lstadd_back(lst, new_link);
	return (0);
}

/*
 *	***** ft_free_image *****
 *
 *	DESCRIPTION:
 *		Frees an image and reinitialiezes its struct values.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_free_image(void *image_ptr)
{
	t_image	*image;

	image = (t_image *)image_ptr;
	if (image->img_ptr)
	{
		mlx_destroy_image(image->mlx_ptr, image->img_ptr);
		image->img_ptr = NULL;
	}
	image->img_buf = NULL;
	image->bits_per_pixel = 0;
	image->size_line = 0;
	image->endian = 0;
	image->mlx_ptr = NULL;
	image->id = NO_ID;
	image->size = (t_point){0, 0};
	free(image);
}

/*
 *	***** ft_free_lst_images *****
 *
 *	DESCRIPTION:
 *		Frees all images in a list.
 *	RETURN:
 *		Void function does not return a value.
 */

void	ft_free_lst_images(t_list **lst)
{
	if (!lst)
		return ;
	ft_lstclear(lst, ft_free_image);
}

/*
 *	***** ft_clear_image *****
 *
 *	DESCRIPTION:
 *		reset all the values of an image to BLACK.
 *	RETURN:
 *		Void function does not return a value.
 */

bool	ft_clear_image(t_list *lst, t_image_id ID)
{
	t_image	*image;

	image = ft_get_image(lst, ID);
	if (!image)
		return (ft_putstr_fd("Error\nImage with matching ID not found \
					during clear.\n", 2), 1);
	ft_paint_bucket(image,
		(t_rect){
		(t_point){0, 0},
		(t_point){image->size.x, image->size.y},
		(t_rgb){0, 0, 0},
	});
	return (0);
}
