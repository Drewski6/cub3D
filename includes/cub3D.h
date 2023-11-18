/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 13:25:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//***** typedefs/structs *****//

typedef struct s_rgb
{
	char		red;
	char		green;
	char		blue;
}				t_rgb;

typedef struct s_map_data
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	t_rgb		f;
	t_rgb		c;
	char		**map;
}				t_map_data;

#endif
