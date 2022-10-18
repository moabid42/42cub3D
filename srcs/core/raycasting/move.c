/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:13:11 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 12:22:00 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(struct cub3d *env, int advance)
{
	double	dir;
	double	plane;

	dir = env->ray.dirx;
	plane = env->ray.planex;
	env->ray.dirx = env->ray.dirx * cos(advance * ROTATION_SPEED)
		- env->ray.diry * sin(advance * ROTATION_SPEED);
	env->ray.diry = dir * sin(advance * ROTATION_SPEED)
		+ env->ray.diry * cos(advance * ROTATION_SPEED);
	env->ray.planex = env->ray.planex * cos(advance * ROTATION_SPEED)
		- env->ray.planey * sin(advance * ROTATION_SPEED);
	env->ray.planey = plane * sin(advance * ROTATION_SPEED)
		+ env->ray.planey * cos(advance * ROTATION_SPEED);
}

void	move_up(struct cub3d *env)
{
	if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)]\
	[(int)(env->player_x + env->ray.dirx * env->ray.speed)]))
		env->player_x += env->ray.dirx * env->ray.speed;
	if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y + \
		env->ray.diry * env->ray.speed)][(int)(env->player_x)]))
		env->player_y += env->ray.diry * env->ray.speed;
}

void	up_down(struct cub3d *env)
{
	if (env->move_flag & 1)
		move_up(env);
	if (env->move_flag & 2)
	{
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)][(int)\
			(env->player_x - env->ray.dirx * env->ray.speed)]))
			env->player_x -= env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y - \
			env->ray.diry * env->ray.speed)][(int)(env->player_x)]))
			env->player_y -= env->ray.diry * env->ray.speed;
	}
}

void	straf(struct cub3d *env)
{
	if (env->move_flag & 16)
	{
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y - env->\
		ray.dirx * env->ray.speed)][(int)(env->player_x)]))
			env->player_y += -env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)][(int)\
		(env->player_x
			+ env->ray.diry * env->ray.speed)]))
			env->player_x += env->ray.diry * env->ray.speed;
	}
	if (env->move_flag & 32)
	{
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y + env->\
		ray.dirx * env->ray.speed)][(int)(env->player_x)]))
			env->player_y -= -env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWENBAOFQT", env->map[(int)(env->player_y)][(int)\
		(env->player_x - env->ray.diry * env->ray.speed)]))
			env->player_x -= env->ray.diry * env->ray.speed;
	}
}

void	ft_move(struct cub3d *env)
{
	if (env->move_flag & 1 || env->move_flag & 2)
		up_down(env);
	if (env->move_flag & 32 || env->move_flag & 16)
		straf(env);
	if (env->move_flag & 4)
		ft_rotate(env, -1);
	if (env->move_flag & 8)
		ft_rotate(env, 1);
}
