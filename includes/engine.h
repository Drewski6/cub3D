/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:24:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/06 12:06:20 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

//***** includes *****//

# include "cub3ddef.h"

//***** defines *****//

# define WIN_X			1900
# define WIN_Y			1000
# define WIN_NAME		"dpentlan - cub3D"
# define FOV			60
# define MOVE_SPEED		0.2
# define MAP_SIZE		500
# define MAP_ORIG_X		10
# define MAP_ORIG_Y		10

//***** enums *****//

typedef enum e_direction
{
	FORWARD_DIR = 0,
	BACKWARD_DIR = 1,
	LEFT_DIR = 2,
	RIGHT_DIR = 3,
	TURN_LEFT = 4,
	TURN_RIGHT = 5,
}	t_direction;

typedef enum e_card_dir
{
	D_NORTH = 0,
	D_EAST = 1,
	D_SOUTH = 2,
	D_WEST = 3,
}	t_card_dir;

//***** typesdefs/structs *****//

typedef struct s_map_data	t_map_data;
typedef struct s_list		t_list;

typedef struct s_ray
{
	double		coord_x;
	double		coord_y;
	double		offset_x;
	double		offset_y;
	double		angle;
	double		dist_from_player;
	t_card_dir	d_wall;
	t_rgb		color;
}				t_ray;

typedef struct s_player
{
	t_pos	pos;
	t_point	coord;
	int		size;
	t_pos	delta;
	double	angle;
}			t_player;

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

		//***** main *****//
int		ft_close_cub3d(t_clear *clear);

		//***** render *****/
bool	ft_prerender(t_engine *engine, t_map_data *map_data);
int		ft_render(t_clear *clear);

		//***** engine *****/
void	ft_free_engine(t_engine *engine);
bool	ft_engine_init(t_engine *engine);

		//***** player *****/
void	ft_rotate_player(t_player *player, t_direction direction);
void	ft_move_player(t_player *player, t_direction direction);
bool	ft_player_init(t_player *player, t_map_data *map_data);
void	ft_update_player_coords(t_player *player, int block_size);
bool	ft_draw_player(t_engine *engine, t_map_data *map_data,
			t_player *player);

		//***** rays *****//
bool	ft_draw_rays(t_engine *engine, t_player *player, t_map_data *map_data);
void	ft_get_ray_size(t_player *player, t_map_data *map_data,
			t_ray *ray, int ray_num);
bool	ft_dir_ray(t_engine *engine, t_player *player, t_map_data *map_data);
void	ft_horiz_check(t_player *player, t_map_data *map_data, t_ray *h_ray,
			int max_dof);
void	ft_vert_check(t_player *player, t_map_data *map_data, t_ray *v_ray,
			int max_dof);
double	ft_distance(double pt1x, double pt1y, double pt2x, double pt2y);
double	ft_fix_fisheye(double player_angle, double ray_angle, double dist);

		//***** mini_map *****/
bool	ft_draw_mini_map(t_engine *engine, t_map_data *map_data);
bool	ft_draw_map_rays(t_engine *engine, t_player *player,
			t_map_data *map_data);

#endif
