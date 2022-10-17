/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:26:08 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 00:29:11 by rdoukali         ###   ########.fr       */
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
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"
#include "../gnl/get_next_line.h"

typedef	enum				e_error
{
	ERROR,
	ZBUFFER_ERROR,
	NB_ARG_ERROR,
	NB_ARG_ERROR_TOO_FEW,
	NB_ARG_ERROR_TOO_MANY,
	FILE_EXT_ERROR,
	SAVE_FLAG_ERROR,
	FILE_READ_ERROR,
	SCREEN_ERROR,
	ARGUMENT_ERROR,
	PATH_ERROR,
	UNKNOW_ARG,
	RGB_ERROR,
	OPEN_ERROR,
	WRITE_ERROR,
	FROM_LST_ERROR,
	MAP_ERROR,
	MAP_ERROR_WRONG_CHAR,
	MAP_ERROR_MANY_POS,
	MAP_ERROR_NO_POS,
	MAP_ERROR_NOT_CLOSED,
	MAP_ERROR_SAME_SIZE,
	MALLOC_ERROR,
	IMG_ERROR,
	IMG_ERROR_WEAPON_1,
	IMG_ERROR_WEAPON_2,
	IMG_ERROR_WEAPON_3,
	IMG_ERROR_WEAPON_4,
	IMG_ERROR_WEAPON_5,
	IMG_ERROR_ITEM,
	TEX_ERROR_N,
	TEX_ERROR_S,
	TEX_ERROR_W,
	TEX_ERROR_E,
	TEX_ERROR_SP,
	TEX_ERROR_SP1,
	TEX_ERROR_D,
	TEX_ERROR_B,
	TEX_ERROR_A,
	TEX_ERROR_T,
	TEX_ERROR_E1,
	TEX_ERROR_E2,
	TEX_ERROR_E3,
	TEX_ERROR_E4,
	TEX_ERROR_E5,
	TEX_ERROR_E6,
	TEX_ERROR_E7,
	TEX_ERROR_E8,
	TEX_ERROR_E9,
	TEX_ERROR_ENNEMY,
	MLX_ERROR,
	TEX_ERROR,
	PIXEL_ERROR,
	COLOR_ERROR,
	SUCCESS
}							t_error;

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

typedef struct				s_save
{
	int						height;
	int						width;
	int						pad;
	unsigned char			*file_header;
	unsigned char			*img_header;
	int						fd;
}							t_save;

struct						data
{
	int						line_index;
	int						screen_w;
	int						screen_h;
	int						map_flag;
	char						*no;
	char						*so;
	char						*we;
	char						*ea;
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
	char					*type;
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

typedef struct				s_move
{
	int						up;
	int						down;
	int						left;
	int						right;
	int						strafl;
	int						strafr;
	int						lean_for;
	int						lean_back;
	int						collision;
}							t_move;

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
	double					spend;
}							t_ray;

typedef struct				s_pos
{
	int						x;
	int						y;
}							t_pos;

struct						cub3d
{
	void					*mlx_ptr;
	void					*win_ptr;
	struct data				arg;
	char					**map;
	int						map_height;
	int						map_width;
	double					player_x;
	double					player_y;
	char					orientation;
	int						height;
	int						width;
	unsigned int			floor;
	unsigned int			ceil;
	int						error;
	t_move					move;
	t_ray					ray;
	t_img					*img;
	t_tex					*tex_s;
	t_tex					*tex_n;
	t_tex					*tex_w;
	t_tex					*tex_e;
	t_tex					*tex_door;
	t_tex					*tex_floor;
	int						save_flag;
	unsigned int			color;
	int						minimap;
};

int							fetch_arguments(struct data *arg, char *buff);

int							check_path(struct data *arg, char *buff);
int							check_path1(char *orientation, char \
		*buff, int i, struct data *arg);
int							check_path2(char *orientation, char \
		*buff, int i, struct data *arg);
int							check_path3(char *orientation, char \
		*buff, int i, struct data *arg);

int							check_map(t_map *map, int count_pos, int i);

t_tex						*ft_new_tex(struct cub3d *env, char *file, char *type);
int							init_items(struct cub3d *env);
struct cub3d				init_env(struct data arg);
t_img						*ft_new_img(struct cub3d *env, char *file);

int							from_rgb_to_hex(t_rgb color);
void						get_arg_for_env(struct cub3d *env, struct data a, int y, int x);
t_img						*ft_new_img(struct cub3d *env, char *file);

int							ft_exit(struct cub3d *env);
int							events(struct cub3d env);

void						ft_move(struct cub3d *env);

int							ft_disp_screen(struct cub3d *env, int x);
int							ft_put_pixel(t_img *img, unsigned int\
		color, int p_x, int p_y);


int							display_sound(struct cub3d *env, t_pos offset,\
		int *numb_tab);
void						display_bullet(struct cub3d *env, t_pos offset,\
		double divider, int *numb_tab);
int							display_life(struct cub3d *env, t_pos offset,\
		int *num_tab);
int							display_target(struct cub3d *env, t_pos offset,\
		int *numb_tab);
int							ft_disp_items(struct cub3d *env);


void						ft_init_ray(struct cub3d *env, int x);
void						ft_direction_ray(struct cub3d *env);
char						ft_hit_ray(struct cub3d *env, char wall_tex);
void						ft_size_ray(struct cub3d *env);
void						ft_wall_tex(struct cub3d *env, char tex);
void						ft_sprite_tex(struct cub3d *env);


int							count_char(char *str, char c);
t_map						*ft_lstlast_map(t_map *lst);
t_map						*ft_lstnew_map(void *content);
char						*withdraw_char(char *str, char c);
void						ft_lstadd_back_map(t_map **alst, t_map *new);
int							ft_lstsize_map(t_map *lst);
void						ft_lstclear_map(t_map **lst);
char						**from_lst_to_tab(t_map *lst);
t_img						*ft_new_image(struct cub3d *env, int width, int height);
void						pixel_tex(t_tex *tex, struct cub3d *env);
char						*pix_color(struct cub3d *env);
void						draw_rectangle(struct cub3d env, int width, int h,\
		int x, int y, int c);
void						open_door(struct cub3d *env, char c, int x, int y);
double						ft_abs(double x);


unsigned char				*create_file_header(struct cub3d *env, int pad);
unsigned char				*create_img_header(int height, int width);
int							write_headers(t_save *save);
int							write_colors(struct cub3d *env, int fd, int height,\
		int width);
int							launch_save(struct cub3d *env);

//minimap
void						draw_square(struct cub3d env, int x, int y, int color);
void						init_minimap(struct cub3d env);


void						ft_free_tex(struct cub3d *env, t_tex *tex);
void						ft_free_img(struct cub3d *env, t_img *img);

int							init_tex(struct cub3d *env);

int							ft_error(int error, struct cub3d *env);
int							ft_error_arg(int error);
int							ft_error_tex_inputs(int error, char *orientation);

void	printer_map(struct data *arg);

void	ray_informations_printer(struct cub3d *cub3d);

bool			cub3d_arg_check(int ac, char **av);

void    new_line_remove(char *line);


#	define INVISI_CHAR "\t\v\r\f "
#	define KEY_UP 13
#	define KEY_RIGHT 2
#	define KEY_LEFT 0
#	define KEY_DOWN 1
#	define ROTATE_LEFT 123
#	define ROTATE_RIGHT 124
#	define KEYPRESS 2
#	define KEYRELEASE 3
#	define KEYPRESSMASK 1
#	define KEYRELEASEMASK 10
#	define SPACE_BAR 49
#	define KEY_EXIT 53
#	define STRUCTURENOTIFYMASK 10001
#	define MINIMAP_SIZE 6
#	define COMPRESSION 24
#	define BYTES_PER_PIX 3
#	define SCREEN_MAX_HEIGHT 1440
#	define SCREEN_MAX_WIDTH 2560

#	define SPEED	1

#	define HEIGHT 1440
#	define WIDTH 2560

#	endif
