/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:15:36 by moabid            #+#    #+#             */
/*   Updated: 2022/11/27 17:15:38 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "macros.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "../gnl/get_next_line.h"

struct				s_rgb
{
	int						r;
	int						g;
	int						b;
};

struct				s_map
{
	char					*line;
	struct s_map			*next;
};

struct					s_data
{
	int						line_index;
	int						screen_w;
	int						screen_h;
	int						map_flag;
	struct s_rgb			floor;
	struct s_rgb			ceil;
	struct s_map			*map;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
};

typedef struct s_tex
{
	void					*tex_ptr;
	int						*tex_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_tex;

struct						s_img
{
	void					*img_ptr;
	int						*img_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
};

typedef struct s_ray
{
	double					planex;
	double					planey;
	double					stepx;
	double					stepy;
	double					dirx;
	double					diry;
	int						tex_x;
	int						tex_y;
	double					rposx;
	double					rposy;
	double					rdirx;
	double					rdiry;
	double					rdisdx;
	double					rdisdy;
	double					rdistx;
	double					rdisty;
	int						rmapx;
	int						rmapy;
	int						wall;
	int						wstart;
	int						wend;
	double					camera;
	int						hit;
	double					rh;
	double					step_tex;
	double					tex_pos;
	double					dist;
	double					speed;
	double					*zbuffer;
}							t_ray;

struct						s_cub3d
{
	void					*mlx_ptr;
	void					*win_ptr;
	struct s_data			arg;
	char					**map;
	double					player_x;
	double					player_y;
	char					orientation;
	int						height;
	int						width;
	unsigned int			floor;
	unsigned int			ceil;
	int						error;
	long long				move_flag;
	t_ray					ray;
	struct s_img			*img;
	t_tex					*tex_s;
	t_tex					*tex_n;
	t_tex					*tex_w;
	t_tex					*tex_e;
	unsigned int			color;
};

int							fetch_arguments(struct s_data *arg, char *buff);
int							check_path(struct s_data *arg, char *buff);
int							check_path1(char *orientation, char \
		*buff, int i, struct s_data *arg);
t_tex						*ft_new_tex(struct s_cub3d *env, char *file, \
		char *type);
struct s_cub3d				env_create(struct s_data arg);
int							from_rgb_to_hex(struct s_rgb color);
void						player_create(struct s_cub3d *env, struct s_data a, \
		int y, int x);
int							ft_exit(struct s_cub3d *env);
bool						cub3d_run(struct s_cub3d env);
void						movements_create(struct s_cub3d *env);
int							frames_display(struct s_cub3d *env, int x);
int							ft_put_pixel(struct s_img *img, \
		unsigned int color, int p_x, int p_y);
void						ft_init_ray(struct s_cub3d *env, int x);
void						ft_direction_ray(struct s_cub3d *env);
char						ft_hit_ray(struct s_cub3d *env, char wall_tex);
void						ft_size_ray(struct s_cub3d *env);
void						ft_wall_tex(struct s_cub3d *env, char tex);
int							count_char(char *str, char c);
struct s_map				*ft_lstlast_map(struct s_map *lst);
struct s_map				*ft_lstnew_map(void *content);
void						ft_lstadd_back_map(struct s_map **alst, \
		struct s_map *new);
int							ft_lstsize_map(struct s_map *lst);
char						**map_list_create(struct s_map *lst);
struct s_img				*ft_new_image(struct s_cub3d *env, \
		int width, int height);
void						pixel_tex(t_tex *tex, struct s_cub3d *env);
char						*pix_color(struct s_cub3d *env);
void						ft_free_tex(struct s_cub3d *env, t_tex *tex);
void						ft_free_img(struct s_cub3d *env, struct s_img *img);
int							texture_init(struct s_cub3d *env);
int							ft_error(int error, struct s_cub3d *env);
int							ft_error_arg(int error);
int							ft_error_tex_inputs(int error, char *orientation);
bool						cub3d_arg_check(int ac, char **av);
void						new_line_remove(char *line);
bool						line_isnotempty(struct s_data *arg, char *line);
int							error(int error);
bool						cub3d_check_map(struct s_map *map, int i);
bool						cub3d_create(struct s_data *arg, char *file);
void						*ft_malloc(size_t size);

///////////////////////////////
//          events.c         //
///////////////////////////////

void						movements_create(struct s_cub3d *env);
void						linear_movement(struct s_cub3d *env);
void						move_up(struct s_cub3d *env);
void						move_down(struct s_cub3d *env);
void						translation(struct s_cub3d *env);
void						right_translation(struct s_cub3d *env);
void						left_translation(struct s_cub3d *env);
void						rotation(struct s_cub3d *env, int advance);

#	endif