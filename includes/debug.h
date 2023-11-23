/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 10:44:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cub3D.h"
# include <stdbool.h>

//***** typedefs *****//

typedef struct s_map_data	t_map_data;

//***** function declarations *****//

void	debug_print_map_data(t_map_data *map_data);
bool	debug_print_coord_data(t_coord *coord, char *name);

#endif
