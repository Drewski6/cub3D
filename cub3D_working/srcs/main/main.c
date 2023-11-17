/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/17 13:41:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"
#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;

	mlx_ptr = mlx_init();
	printf("Hello cub3D: %d\n", WORKING);
	printf("Checking github status\n");
	printf("ft_strlen: %ld\n", ft_strlen("hi"));
	win_ptr = mlx_new_window(mlx_ptr, 100, 100, "whats up");
	img_ptr = mlx_new_image(mlx_ptr, 100, 100);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	return (0);
}
