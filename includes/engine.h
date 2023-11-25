/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:24:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/25 09:52:53 by dpentlan         ###   ########.fr       */
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
# define MAP_SIZE 1000
# define MAP_ORIG_X 10
# define MAP_ORIG_Y 10
# define MAP_BG_COLOR	(t_rgb){40, 40, 40}
# define MAP_FG_COLOR	(t_rgb){240, 240, 240}

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

//***** enums *****//

typedef enum e_image_id
{
	NO_ID = 0,
	BG_IMAGE_C = 1,
	BG_IMAGE_F = 2,
	MINI_MAP = 3,
}	t_image_id;

//***** typesdefs/structs *****//

typedef struct s_map_data	t_map_data;
typedef struct s_list		t_list;

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

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_player
{
	t_pos	pos;
}			t_player;

typedef struct s_image
{
	void		*img_ptr;
	char		*img_buf;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	void		*mlx_ptr;
	t_image_id	id;
	t_point		size;
}				t_image;

typedef struct s_engine
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_list		*lst_images;
}			t_engine;

// t_clear is a struct for use with mlx_hook so the program can close properly.
// Only one address can be passed to the mlx_hook family of functions.
typedef struct s_clear
{
	t_engine	*engine;
	t_map_data	*map_data;
}			t_clear;

//***** function declarations *****//

		//***** render *****/
bool	ft_render(t_engine *engine, t_map_data *map_data, t_player *player);
bool	ft_prerender(t_engine *engine, t_map_data *map_data);
		//***** engine *****/
void	ft_free_engine(t_engine *engine);
bool	ft_engine_init(t_engine *engine);
		//***** keys *****/
int		ft_key_press(int key, void *param);
		//***** drawing *****/
void	ft_img_buf_set_px_color(t_image *image, t_rgb color, int x, int y);
void	ft_paint_bucket(t_image *image, t_rect rect);
		//***** player *****/
bool	ft_player_init(t_player *player, t_map_data *map_data);
void	ft_draw_player(t_player *player);
		//***** images *****/
bool	ft_image_init(t_image *image,
			void *mlx_ptr, t_image_id ID, t_point size);
bool	ft_add_image(t_list **lst, void *mlx_ptr, t_image_id ID, t_point size);
void	ft_free_image(void *image_ptr);
void	ft_free_lst_images(t_list **lst);
t_image	*ft_get_image(t_list *lst, t_image_id ID);
bool	ft_send_image_to_window(t_engine *engine, t_list *lst, t_image_id ID,
			t_point start);
bool	ft_create_rect_image(t_engine *engine, t_image_id ID,
			t_point size, t_rgb color);
		//***** map *****/
bool	ft_draw_map(t_engine *engine, t_map_data *map_data);

#endif
