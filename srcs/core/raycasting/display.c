/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:34:45 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 18:22:11 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_put_pixel(struct s_img  *img, unsigned int color, int p_x, int p_y)
{
	if (p_y >= img->height || p_x >= img->width || p_x < 0
	|| p_y < 0 || ((p_y * img->width + p_x) >= (img->width * img->height - 1)))
		return (PIXEL_ERROR);
	img->img_data[p_y * img->width + p_x] = color;
	return (SUCCESS);
}

char	*draw_pixels(struct cub3d *env, int x, int y, int height)
{
	char *tex_path;

	while (y < env->ray.wstart)
		ft_put_pixel(env->img, env->ceil, x, y++);
	while (y >= env->ray.wstart && y <= env->ray.wend)
	{
		env->ray.tex_y = (int)env->ray.tex_pos & (height - 1);
		env->ray.tex_pos += env->ray.step_tex;
		tex_path = pix_color(env);
		ft_put_pixel(env->img, env->color, x, y);
		y++;
	}
	while (y < env->height)
		ft_put_pixel(env->img, env->floor, x, y++);
	return (tex_path);
}
char		*display(struct cub3d *env, int x, char tex, int y)
{
	int		height;

	if (tex == 'E')
		height = env->tex_e->height;
	else if (tex == 'N')
		height = env->tex_n->height;
	else if (tex == 'W')
		height = env->tex_w->height;
	else if (tex == 'S')
		height = env->tex_s->height;
	return (draw_pixels(env, x, y, height));
}

int			frames_display(struct cub3d *env, int x)
{
	char tex;

	while (x < env->width)
	{
		ft_init_ray(env, x);
		ft_direction_ray(env);
		tex = ft_hit_ray(env, 0);
		ft_size_ray(env);
		ft_wall_tex(env, tex);
		display(env, x++, tex, 0);
		env->ray.zbuffer[x] = env->ray.dist;
	}
	return (SUCCESS);
}
