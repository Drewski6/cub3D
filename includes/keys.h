/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:03:10 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 13:41:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

//***** includes *****//

# include "engine.h"
# include <X11/keysym.h>
# include <X11/X.h>

//***** defines *****//

# define HOME_PC
# ifdef HOME_PC
#  define ESC			65307
#  define L_ARROW		65361
#  define U_ARROW		65362
#  define R_ARROW		65363
#  define D_ARROW		65364
#  define W_KEY			122
#  define A_KEY			113
#  define S_KEY			115
#  define D_KEY			100
# endif

//# define SCHOOL_PC
# ifdef SCHOOL_PC
#  define ESC			0
#  define L_ARROW		0 
#  define U_ARROW		0
#  define R_ARROW		0
#  define D_ARROW		0
#  define W_KEY			0
#  define A_KEY			0
#  define S_KEY			0
#  define D_KEY			0
# endif

//***** function declaractions *****//

bool	ft_hooks_cub3d(t_clear *clear);
int		ft_key_press(int key, void *param);
int		ft_key_release(int key, void *param);

#endif
