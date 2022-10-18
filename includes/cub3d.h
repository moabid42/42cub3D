/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:26:08 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 16:26:57 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_H
#	define CUB3D_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>

#include "macros.h"
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "../gnl/get_next_line.h"



typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct				s_map
{
	char					*line;
	struct s_map			*next;
}							t_map;

struct						data
{
	int						line_index;
	int						screen_w;
	int						screen_h;
	int						map_flag;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	t_rgb					floor;
	t_rgb					ceil;
	t_map					*map;
};

typedef	struct				s_tex
{
	void					*tex_ptr;
	int						*tex_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_tex;

typedef	struct				s_img
{
	void					*img_ptr;
	int						*img_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_img;

typedef struct				s_ray
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

struct						cub3d
{
	void					*mlx_ptr;
	void					*win_ptr;
	struct data				arg;
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
	t_img					*img;
	t_tex					*tex_s;
	t_tex					*tex_n;
	t_tex					*tex_w;
	t_tex					*tex_e;
	unsigned int			color;
};

int							fetch_arguments(struct data *arg, char *buff);

int							check_path(struct data *arg, char *buff);
int							check_path1(char *orientation, char \
		*buff, int i, struct data *arg);

int							check_map(t_map *map, int count_pos, int i);

t_tex						*ft_new_tex(struct cub3d *env, char *file, char *type);
int							init_items(struct cub3d *env);
struct cub3d				env_create(struct data arg);
t_img						*ft_new_img(struct cub3d *env, char *file);

int							from_rgb_to_hex(t_rgb color);
void						player_create(struct cub3d *env, struct data a, int y, int x);
t_img						*ft_new_img(struct cub3d *env, char *file);

int							ft_exit(struct cub3d *env);
bool						cub3d_run(struct cub3d env);

void						ft_move(struct cub3d *env);

int							ft_disp_screen(struct cub3d *env, int x);
int							ft_put_pixel(t_img *img, unsigned int\
		color, int p_x, int p_y);


void						ft_init_ray(struct cub3d *env, int x);
void						ft_direction_ray(struct cub3d *env);
char						ft_hit_ray(struct cub3d *env, char wall_tex);
void						ft_size_ray(struct cub3d *env);
void						ft_wall_tex(struct cub3d *env, char tex);


int							count_char(char *str, char c);
t_map						*ft_lstlast_map(t_map *lst);
t_map						*ft_lstnew_map(void *content);
char						*withdraw_char(char *str, char c);
void						ft_lstadd_back_map(t_map **alst, t_map *new);
int							ft_lstsize_map(t_map *lst);
void						ft_lstclear_map(t_map **lst);
char						**map_list_create(t_map *lst);
t_img						*ft_new_image(struct cub3d *env, int width, int height);
void						pixel_tex(t_tex *tex, struct cub3d *env);
char						*pix_color(struct cub3d *env);
double						ft_abs(double x);


void						ft_free_tex(struct cub3d *env, t_tex *tex);
void						ft_free_img(struct cub3d *env, t_img *img);

int							texture_init(struct cub3d *env);

int							ft_error(int error, struct cub3d *env);
int							ft_error_arg(int error);
int							ft_error_tex_inputs(int error, char *orientation);

void						printer_map(struct data *arg);

void						ray_informations_printer(struct cub3d *cub3d);

bool						cub3d_arg_check(int ac, char **av);

void    					new_line_remove(char *line);

bool						line_isnotempty(struct data *arg, char *line);

int	error(int error);

bool						cub3d_check_map(t_map *map, int i);

bool						cub3d_create(struct data *arg, char *file);

#	endif
