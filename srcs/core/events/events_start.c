/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:00:20 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 18:48:10 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_hold(int key, struct cub3d *env)
{
	if (key == KEY_UP)
		set_flag(env->move_flag, 1);
	else if (key == KEY_DOWN)
		set_flag(env->move_flag, 2);
	else if (key == ROTATE_LEFT)
		set_flag(env->move_flag, 4);
	else if (key == ROTATE_RIGHT)
		set_flag(env->move_flag, 8);
	else if (key == KEY_LEFT)
		set_flag(env->move_flag, 16);
	else if (key == KEY_RIGHT)
		set_flag(env->move_flag, 32);
	else if (key == KEY_EXIT)
		ft_exit(env);
	return (SUCCESS);
}


int		key_release(int key, struct cub3d *env)
{
	if (key == KEY_UP)
		unset_flag(env->move_flag, 0);
	else if (key == KEY_DOWN)
		unset_flag(env->move_flag, 1);
	else if (key == ROTATE_LEFT)
		unset_flag(env->move_flag, 2);
	else if (key == ROTATE_RIGHT)
		unset_flag(env->move_flag, 3);
	else if (key == KEY_LEFT)
		unset_flag(env->move_flag, 4);
	else if (key == KEY_RIGHT)
		unset_flag(env->move_flag, 5);
	return (SUCCESS);
}

int		frames_run(struct cub3d *env)
{
	ft_free_img(env, env->img);
	if ((env->img = ft_new_image(env, env->width, env->height)) == NULL)
	{
		env->error = IMG_ERROR;
		ft_error(env->error, env);
		return (IMG_ERROR);
	}
	movements_create(env);
	frames_display(env, 0);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->img_ptr, 0,
		0);
	return (SUCCESS);
}

bool		cub3d_run(struct cub3d env)
{
	while (env.width % 4)
		env.width++;
    if (!(env.win_ptr = mlx_new_window(env.mlx_ptr, 1, 1, "Cub3D")))
        return (false);
	else
	{
		if (!(env.win_ptr = mlx_new_window(env.mlx_ptr, env.width, \
		env.height, "Cub3D")))
			return (false);
	}
	mlx_hook(env.win_ptr, 17, STRUCTURENOTIFYMASK, ft_exit, &env);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, key_hold, &env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &env);
	mlx_loop_hook(env.mlx_ptr, frames_run, &env);
	mlx_loop(env.mlx_ptr);
	return (true);
}
