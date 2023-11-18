/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:26 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 13:26:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

//***** typedefs *****//

typedef struct s_map_data	t_map_data;

//***** function prototypes *****//

void	debug_print_table(char **table);
void	debug_print_map_data(t_map_data *map_data);

#endif