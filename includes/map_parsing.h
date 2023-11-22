/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:40:07 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/22 14:28:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSING_H
# define MAP_PARSING_H

//***** includes *****//

# include <stdbool.h>

//***** typedefs *****//

typedef struct s_map_data	t_map_data;
typedef struct s_coord		t_coord;

//***** function prototypes *****//

bool	ft_map_data(t_map_data *map_data, char *filename);
bool	ft_map_validation(t_map_data *map_data);
bool	ft_map_data_validation(t_map_data *map_data);
bool	ft_read_in_map(t_map_data *map_data, int fd, char **line);
bool	ft_read_in_elements(t_map_data *map_data, int fd, char **line);
void	ft_get_coord_neighbors(t_coord *coord, char **map, int c);
bool	ft_map_crawl(char **map, t_coord *head);
bool	ft_map_crawl_get_start(char **map, t_coord *head);

#endif
