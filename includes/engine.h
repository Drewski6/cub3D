/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:24:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/24 00:10:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

//***** includes *****//

# include <stdbool.h>

//***** defines *****//

# define WIN_X 1024
# define WIN_Y 512
# define WIN_NAME "dpentlan - cub3D"
# define MAP_X 500
# define MAP_Y 500

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

//***** typesdefs/structs *****//

typedef struct s_map_data	t_map_data;

typedef struct s_image
{
	void		*img_ptr;
	char		*img_buf;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_engine
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		bg_image;
	t_image		map_image;
}			t_engine;

// t_clear is a struct for use with mlx_hook so the program can close properly.
// Only one address can be passed to the mlx_hook family of functions.
typedef struct s_clear
{
	t_engine	*engine;
	t_map_data	*map_data;
}			t_clear;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_player
{
	t_point	pos;
}			t_player;

//***** function declarations *****//

bool	ft_render(t_map_data *map_data, t_engine *engine, t_player *player);
void	ft_free_engine(t_engine *engine);
bool	ft_engine_init(t_engine *engine);
int		ft_key_press(int key, void *param);
bool	ft_images_init(t_image *image, void *mlx_ptr, int x, int y);
void	ft_img_buf_set_px_color(t_image *image, t_rgb *color, int x, int y);
void	ft_paint_bucket(t_image *image, t_rgb *color, int x, int y);
void	ft_draw_background(t_engine *engine,
			t_image *bg_image, t_rgb *f, t_rgb *c);
void	ft_draw_map(t_engine *engine);
bool	ft_player_init(t_player *player, t_map_data *map_data);
void	ft_draw_player(t_player *player);

#endif
