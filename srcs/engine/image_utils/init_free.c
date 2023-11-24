/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:33:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 11:18:29 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include "mlx.h"

/*
 *	***** ft_image_init *****
 *
 *	DESCRIPTION:
 *		Initializes the image to be used in cub3D
 *	RETURN:
 *		Bool function returns 0 on success and 1 on error.
 */

bool	ft_image_init(t_image *image, void *mlx_ptr, int x, int y)
{
	image->mlx_ptr = mlx_ptr;
	image->img_ptr = mlx_new_image(mlx_ptr,
			x, y);
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
 *		Returns an integer indicating the index in the list of the new image.
 */

int	ft_add_image(t_list *lst, void *mlx_ptr, t_image_id ID, t_point size)
{
	(void) lst;
	(void) mlx_ptr;
	(void) size;
	(void) ID;

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
	image->ID = NO_ID;
	image->size = (t_point){0, 0};
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
