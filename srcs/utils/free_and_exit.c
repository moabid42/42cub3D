/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:40:57 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 19:40:59 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(struct s_cub3d *env)
{
	if (!env->error)
	{
		ft_free_img(env, env->img);
		ft_free_tex(env, env->tex_s);
		ft_free_tex(env, env->tex_n);
		ft_free_tex(env, env->tex_w);
		ft_free_tex(env, env->tex_e);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	exit(0);
	return (SUCCESS);
}

void	ft_free_tex(struct s_cub3d *env, t_tex *tex)
{
	if (tex)
	{
		mlx_destroy_image(env->mlx_ptr, tex->tex_ptr);
		free(tex);
		tex = NULL;
	}
}

void	ft_free_img(struct s_cub3d *env, struct s_img  *img)
{
	if (img)
	{
		mlx_destroy_image(env->mlx_ptr, img->img_ptr);
		free(img);
		img = NULL;
	}
}
