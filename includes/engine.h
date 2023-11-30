/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:24:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 12:22:09 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

//***** includes *****//

# include <stdbool.h>

//***** defines *****//

# define WIN_X			1024
# define WIN_Y			512
# define WIN_NAME		"dpentlan - cub3D"
# define MAP_SIZE		1000
# define MAP_ORIG_X		10
# define MAP_ORIG_Y		10
# define MOVE_SPEED		0.1
# define PI				3.1415926535
# define RADS_PER_DEG	0.0174533
# define FOV			60

//***** enums *****//

typedef enum e_image_id
{
	NO_ID = 0,
	BG_IMAGE_C = 1,
	BG_IMAGE_F = 2,
	MINI_MAP = 3,
}	t_image_id;

typedef enum e_direction
{
	FORWARD_DIR = 0,
	BACKWARD_DIR = 1,
	LEFT_DIR = 2,
	RIGHT_DIR = 3,
	TURN_LEFT = 4,
	TURN_RIGHT = 5,
}	t_direction;

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

typedef struct s_ray
{
	double	coord_x;
	double	coord_y;
	double	offset_x;
	double	offset_y;
	double	angle;
	double	dist_from_player;
}		t_ray;

typedef struct s_player
{
	t_pos	pos;
	t_point	coord;
	int		size;
	t_pos	delta;
	double	angle;
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
	t_player	*player;
}			t_clear;

//***** function declarations *****//

		//***** render *****/
int		ft_render(t_clear *clear);
bool	ft_prerender(t_engine *engine, t_map_data *map_data);
		//***** engine *****/
void	ft_free_engine(t_engine *engine);
bool	ft_engine_init(t_engine *engine);
		//***** drawing *****/
void	ft_img_buf_set_px_color(t_image *image, t_rgb color, int x, int y);
void	ft_paint_bucket(t_image *image, t_rect rect);
void	ft_px_put_rect(t_engine *engine, t_rect rect);
int		ft_color_to_int(t_rgb color);
bool	ft_bresenhams_line(t_engine *engine,
			t_point from, t_point to, int color);
		//***** player *****/
bool	ft_player_init(t_player *player, t_map_data *map_data);
bool	ft_draw_player(t_engine *engine, t_map_data *map_data,
			t_player *player);
void	ft_move_player(t_player *player, t_direction direction);
void	ft_rotate_player(t_player *player, t_direction direction);
bool	ft_draw_rays(t_engine *engine, t_player *player, t_map_data *map_data);
void	ft_horiz_check(t_player *player, t_map_data *map_data, t_ray *h_ray,
			int max_dof);
void	ft_vert_check(t_player *player, t_map_data *map_data, t_ray *v_ray,
			int max_dof);
double	ft_distance(double pt1x, double pt1y, double pt2x, double pt2y);
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
