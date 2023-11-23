/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:24:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 11:17:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

//***** includes *****//

# include <stdbool.h>

//***** defines *****//

# define WIN_X 500
# define WIN_Y 500
# define WIN_NAME "dpentlan - cub3D"

//***** typesdefs/structs *****//

typedef struct s_engine
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_engine;

//***** function declarations *****//

void	ft_free_engine(t_engine *engine);
bool	ft_engine_init(t_engine *engine);

#endif
