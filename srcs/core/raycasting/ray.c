/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:51 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 21:02:54 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_ray(struct cub3d *env, int x)
{
	env->ray.camera = 2 * x / (double)(env->width) - 1;
	env->ray.rposx = env->player_x;
	env->ray.rposy = env->player_y;
	env->ray.rdirx = -env->ray.dirx + env->ray.planex * env->ray.camera;
	env->ray.rdiry = -env->ray.diry + env->ray.planey * env->ray.camera;
	env->ray.rmapx = (int)env->ray.rposx;
	env->ray.rmapy = (int)env->ray.rposy;
	env->ray.rdisdx = sqrt(1 + (env->ray.rdiry * env->ray.rdiry) /
		(env->ray.rdirx * env->ray.rdirx));
	env->ray.rdisdy = sqrt(1 + (env->ray.rdirx * env->ray.rdirx) /
		(env->ray.rdiry * env->ray.rdiry));
	env->ray.hit = 0;
}

void		ft_direction_ray(struct cub3d *env)
{
	if (env->ray.rdirx > 0)
	{
		env->ray.stepx = -1;
		env->ray.rdistx = (env->ray.rposx - env->ray.rmapx) * env->ray.rdisdx;
	}
	else
	{
		env->ray.stepx = 1;
		env->ray.rdistx = (env->ray.rmapx + 1.0 - env->ray.rposx) *
			env->ray.rdisdx;
	}
	if (env->ray.rdiry > 0)
	{
		env->ray.stepy = -1;
		env->ray.rdisty = (env->ray.rposy - env->ray.rmapy) * env->ray.rdisdy;
	}
	else
	{
		env->ray.stepy = 1;
		env->ray.rdisty = (env->ray.rmapy + 1.0 - env->ray.rposy) *
			env->ray.rdisdy;
	}
}

char		get_wall_tex(struct cub3d *env)
{
	char	wall_tex;

	if (env->ray.wall == 0)
	{
		if (env->ray.stepx > 0 && env->ray.rmapx > \
		(int)env->ray.rposx && env->ray.wall == 0)
			wall_tex = 'W';
		if (env->ray.stepx < 0 && env->ray.rmapx < (int)\
		env->ray.rposx && env->ray.wall == 0)
			wall_tex = 'E';
	}
	if (env->ray.wall == 1)
	{
		if (env->ray.stepy > 0 && env->ray.rmapy > (int)env->ray.\
		rposy && env->ray.wall == 1)
			wall_tex = 'S';
		if (env->ray.stepy < 0 && env->ray.rmapy < (int)env->ray.\
		rposy && env->ray.wall - 0)
			wall_tex = 'N';
	}
	return (wall_tex);
}

char		ft_hit_ray(struct cub3d *env, char wall_tex)
{
	while (env->ray.hit == 0)
	{
		if (env->ray.rdistx < env->ray.rdisty)
		{
			env->ray.rdistx += env->ray.rdisdx;
			env->ray.rmapx += env->ray.stepx;
			env->ray.wall = 0;
		}
		else
		{
			env->ray.rdisty += env->ray.rdisdy;
			env->ray.rmapy += env->ray.stepy;
			env->ray.wall = 1;
		}
		if (!ft_strchr("023ENSWBAOTFQ", env->map[env->ray.rmapy]\
					[env->ray.rmapx]))
			env->ray.hit = 1;
		wall_tex = get_wall_tex(env);
	}
	return (wall_tex);
}

void		ft_size_ray(struct cub3d *env)
{
	if (env->ray.wall == 0)
		env->ray.dist = fabs((env->ray.rmapx - env->ray.rposx
					+ (1 - env->ray.stepx) / 2) / env->ray.rdirx);
	if (env->ray.wall == 1)
		env->ray.dist = fabs((env->ray.rmapy - env->ray.rposy
					+ (1 - env->ray.stepy) / 2) / env->ray.rdiry);
	env->ray.rh = fabs((env->height / env->ray.dist));
	env->ray.rh -= env->height / 50;
	env->ray.wstart = (-1 * (env->ray.rh)) / 2 + env->height / 2;
	env->ray.wend = env->ray.rh / 2 + env->height / 2;
	if (env->ray.wstart < 0)
		env->ray.wstart = 0;
	if (env->ray.wend >= env->height)
		env->ray.wend = env->height - 1;
}
