/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:36:48 by dpentlan          #+#    #+#             */
/*   Updated: 2023/12/02 11:04:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

//***** includes *****//

# include "cub3ddef.h"

//***** enums *****//

typedef enum e_image_id
{
	NO_ID = 0,
	RAYS = 1,
	MINI_MAP = 2,
	NT = 3,
	ST = 4,
	ET = 5,
	WT = 6,
}	t_image_id;

//***** typedefs/structs *****//

typedef struct s_list		t_list;
typedef struct s_engine		t_engine;
typedef struct s_map_data	t_map_data;

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

//***** function declarations *****//

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
bool	ft_clear_image(t_list *lst, t_image_id ID);

		//***** drawing *****/
int		ft_color_to_int(t_rgb color);
t_rgb	ft_int_to_color(int color);
void	ft_img_buf_set_px_color(t_image *image, t_rgb color, int x, int y);
void	ft_paint_bucket(t_image *image, t_rect rect);
void	ft_px_put_rect(t_engine *engine, t_rect rect);
bool	ft_bresenhams_line(t_engine *engine,
			t_point from, t_point to, int color);

		//***** textures *****/
bool	ft_load_textures(t_engine *engine, t_map_data *map_data);

#endif
