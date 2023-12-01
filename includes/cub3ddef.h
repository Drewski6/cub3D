/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3ddef.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:41:25 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/01 16:50:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DDEF_H
# define CUB3DDEF_H

//***** includes *****//

# include <stdbool.h>

//***** defines *****//

# define PI				3.1415926535
# define RADS_PER_DEG	0.0174533

//***** typedefs/structs *****//

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_rect
{
	t_point	top_left;
	t_point	bottom_right;
	t_rgb	color;
}		t_rect;

#endif
