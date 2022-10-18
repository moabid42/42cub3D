/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:06:16 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 16:31:00 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			init_raybuffer(struct cub3d *env)
{
	if (!(env->ray.zbuffer = malloc(sizeof(double) * (env->width + 1))))
		return (ZBUFFER_ERROR);
	return (SUCCESS);
}

void		init_env_orientation(struct cub3d *env)
{
	if (env->orientation == 'N')
	{
		env->ray.diry = -0.99;
		env->ray.planex = -0.80;
	}
	if (env->orientation == 'S')
	{
		env->ray.diry = 0.99;
		env->ray.planex = 0.80;
	}
	if (env->orientation == 'E')
	{
		env->ray.dirx = 0.99;
		env->ray.planey = -0.80;
	}
	if (env->orientation == 'W')
	{
		env->ray.dirx = -0.99;
		env->ray.planey = 0.80;
	}
}

void		env_data_fill(struct cub3d *env, struct data arg)
{
	env->width = arg.screen_w;
	env->height = arg.screen_h;
	env->floor = from_rgb_to_hex(arg.floor);
	env->ceil = from_rgb_to_hex(arg.ceil);
	env->arg = arg;
	init_env_orientation(env);
	env->mlx_ptr = mlx_init();
	env->player_x += 0.5;
	env->player_y += 0.5;
}

struct cub3d 		env_create(struct data arg)
{
	struct cub3d 	env;

	ft_bzero(&env, sizeof(struct cub3d ));
	ft_bzero(&env.ray, sizeof(t_ray));
	player_create(&env, arg, 0, 0);
	env.ray.speed = SPEED;
	env.map = map_list_create(arg.map);
	env_data_fill(&env, arg);
	texture_init(&env);
	if (init_raybuffer(&env) != SUCCESS)
		ft_error(env.error, &env);
	return (env);
}
