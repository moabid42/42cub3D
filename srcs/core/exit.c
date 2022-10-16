/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:01:59 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 01:38:21 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(struct cub3d *env)
{
	if (!env->error)
	{
		ft_free_img(env, env->img);
		ft_free_tex(env, env->tex_s);
		ft_free_tex(env, env->tex_n);
		ft_free_tex(env, env->tex_w);
		ft_free_tex(env, env->tex_e);
		ft_free_tex(env, env->tex_door);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	exit(0);
	return (SUCCESS);
}
