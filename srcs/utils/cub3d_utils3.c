/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:27:28 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 01:38:21 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img		*ft_new_image(struct cub3d *env, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->img_ptr = mlx_new_image(env->mlx_ptr, width, height)))
		return (NULL);
	if (!(img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian)))
		return (NULL);
	img->width = width;
	img->height = height;
	return (img);
}

void		pixel_tex(t_tex *tex, struct cub3d *env)
{
	if (tex->width * env->ray.tex_y + env->ray.tex_x < (tex->width *\
				tex->height))
		env->color = tex->tex_data[tex->width * env->ray.tex_y +\
					env->ray.tex_x];
}

char		*get_output_wall(struct cub3d *env)
{
	if (env->ray.stepx < 0 && env->ray.rmapx < (int)env->ray.\
rposx && env->ray.wall == 0)
	{
		pixel_tex(env->tex_e, env);
		return (env->arg.ea);
	}
	if (env->ray.stepx > 0 && env->ray.rmapx > (int)env->ray.rposx\
	&& env->ray.wall == 0)
	{
		pixel_tex(env->tex_w, env);
		return (env->arg.we);
	}
	if (env->ray.stepy < 0 && env->ray.rmapy < (int)env->ray.rposy &&\
	env->ray.wall - 0)
	{
		pixel_tex(env->tex_n, env);
		return (env->arg.no);
	}
	if (env->ray.stepy > 0 && env->ray.rmapy > (int)\
	env->ray.rposy && env->ray.wall == 1)
		pixel_tex(env->tex_s, env);
	return (env->arg.so);
}

char		*pix_color(struct cub3d *env, int sprite)
{
	char	*output;

	output = NULL;
	sprite = 0;
	env = NULL;	
	// if (!sprite && !env->ray.door)
	// {
	// 	output = get_output_wall(env);
	// }
	// if (env->ray.door)
	// {
	// 	pixel_tex(env->tex_door, env);
	// 	output = env->arg.door;
	// }
	// if (sprite && env->ray.sprite)
	// {
	// 	pixel_tex(env->tex_sprite, env);
	// 	output = env->arg.sprite;
	// }
	return (output);
}

