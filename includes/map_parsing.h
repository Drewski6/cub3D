/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:40:07 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/18 13:05:55 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSING_H
# define MAP_PARSING_H

//***** includes *****//

# include <stdbool.h>

//***** typedefs *****//

typedef struct s_map_data t_map_data;

//***** function prototypes *****//

bool	ft_init_map(t_map_data *map_data, char *file_name);

#endif
