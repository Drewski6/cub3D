/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 13:23:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//***** includes *****//

# include "engine.h"

//***** typedefs/structs *****//

typedef struct s_list	t_list;

/*
 *	7, 6, 5,
 *	0, C, 4,
 *	1, 2, 3
 */

typedef struct s_coord
{
	int				x;
	int				y;
	int				source;
	unsigned char	neighbors;
}					t_coord;

typedef struct s_map_data
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	t_rgb		f;
	t_rgb		c;
	char		**map;
	t_coord		start_pos;
	t_point		size;
	int			map_block_size;
}				t_map_data;

//***** function declaractions *****//

int		ft_close_cub3d(t_clear *clear);

#endif
