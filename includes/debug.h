/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/01 14:50:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cub3ddef.h"

//***** typedefs *****//

typedef struct s_map_data	t_map_data;
typedef struct s_coord		t_coord;

//***** function declarations *****//

void	debug_print_map_data(t_map_data *map_data);
bool	debug_print_coord_data(t_coord *coord, char *name);

#endif
