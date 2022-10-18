/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:27:28 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 16:37:57 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

struct s_img 		*ft_new_image(struct cub3d *env, int width, int height)
{
	struct s_img 	*img;

	if (!(img = malloc(sizeof(struct s_img ))))
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
	// ray_informations_printer(env);
	if (env->ray.stepx < 0 && env->ray.rmapx < (int)env->ray.rposx && env->ray.wall == 0)
	{
		pixel_tex(env->tex_e, env);
		return (env->arg.ea);
	}
	if (env->ray.stepx > 0 && env->ray.rmapx > (int)env->ray.rposx
	&& env->ray.wall == 0)
	{
		pixel_tex(env->tex_w, env);
		return (env->arg.we);
	}
	if (env->ray.stepy < 0 && env->ray.rmapy < (int)env->ray.rposy &&
	env->ray.wall - 0)
	{
		pixel_tex(env->tex_n, env);
		return (env->arg.no);
	}
	if (env->ray.stepy > 0 && env->ray.rmapy > (int)env->ray.rposy && env->ray.wall == 1)
	{
		pixel_tex(env->tex_s, env);
	}
	return (env->arg.so);
}

char		*pix_color(struct cub3d *env)
{
	char	*output;

	output = NULL;
	output = get_output_wall(env);
	return (output);
}

