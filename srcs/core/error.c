/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:53:06 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 01:38:21 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_tex(int error, struct cub3d *env)
{
	env->error = error;
	if (env->tex_n)
		ft_free_tex(env, env->tex_n);
	if (env->tex_s)
		ft_free_tex(env, env->tex_s);
	if (env->tex_w)
		ft_free_tex(env, env->tex_w);
	if (env->tex_e)
		ft_free_tex(env, env->tex_e);
	if (env->tex_door)
		ft_free_tex(env, env->tex_door);
	ft_putstr("Error\nProblem with textures loading");
}

int		ft_error(int error, struct cub3d *env)
{
	if (error == ZBUFFER_ERROR)
	{
		ft_putstr("Error\nProblem with memory allocation");
	}
	if (error == FROM_LST_ERROR)
	{
		ft_putstr("Error\nProblem with map creation");
	}
	if (error == TEX_ERROR)
		ft_error_tex(error, env);
	ft_exit(env);
	return (SUCCESS);
}
