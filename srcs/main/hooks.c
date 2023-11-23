/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:16:49 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 23:35:10 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdbool.h>
#include "libft.h"
#include "cub3D.h"

bool	ft_hooks_cub3d(t_clear *clear)
{
	if (0
		|| !mlx_hook(clear->engine->win_ptr, 17, 0,
			&ft_close_cub3d, (void *)clear)
		|| !mlx_key_hook(clear->engine->win_ptr, &ft_key_press, (void *)clear)
	)
		return (ft_putstr_fd(
				"Error\nMLX hook functions returned error.\n", 2), 1);
	return (0);
}
