/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:23:11 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 20:10:56 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

///////////////////////////////////////////////////////////////////////

void	right_translation(struct s_cub3d *env)
{
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y - env->ray.dirx
				* env->ray.speed)][(int)(env->player_x)]))
		env->player_y += -env->ray.dirx * env->ray.speed;
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y)]
		[(int)(env->player_x + env->ray.diry * env->ray.speed)]))
		env->player_x += env->ray.diry * env->ray.speed;
}

void	left_translation(struct s_cub3d *env)
{
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y + env->ray.dirx
				* env->ray.speed)][(int)(env->player_x)]))
		env->player_y -= -env->ray.dirx * env->ray.speed;
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y)]
		[(int)(env->player_x - env->ray.diry * env->ray.speed)]))
		env->player_x -= env->ray.diry * env->ray.speed;
}

///////////////////////////////////////////////////////////////////////

void	move_up(struct s_cub3d *env)
{
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y)]
		[(int)(env->player_x + env->ray.dirx * env->ray.speed)]))
		env->player_x += env->ray.dirx * env->ray.speed;
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y
				+ env->ray.diry * env->ray.speed)][(int)(env->player_x)]))
		env->player_y += env->ray.diry * env->ray.speed;
}

void	move_down(struct s_cub3d *env)
{
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y)]
		[(int)(env->player_x - env->ray.dirx * env->ray.speed)]))
		env->player_x -= env->ray.dirx * env->ray.speed;
	if (ft_strchr("0SWEN", env->map[(int)(env->player_y
				- env->ray.diry * env->ray.speed)][(int)(env->player_x)]))
		env->player_y -= env->ray.diry * env->ray.speed;
}

///////////////////////////////////////////////////////////////////////

void	rotation(struct s_cub3d *env, int advance)
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
