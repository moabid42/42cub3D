/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:06:16 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/17 11:57:33 by moabid           ###   ########.fr       */
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

void		init_env_2(struct cub3d *env, struct data arg)
{
	env->width = arg.screen_w;
	env->height = arg.screen_h;
	// printf("The floor is %d and the ceiling is %d", arg.floor, arg.ceil);
	env->floor = from_rgb_to_hex(arg.floor);
	env->ceil = from_rgb_to_hex(arg.ceil);
	env->arg = arg;
	init_env_orientation(env);
	env->mlx_ptr = mlx_init();
	env->player_x += 0.5;
	env->player_y += 0.5;
	env->minimap = 1;
}

//create a function that s gonna print the content of arg map
void	printer_map(struct data *arg)
{
	t_map	*tmp;

	tmp = arg->map;
	while (tmp)
	{
		printf("[%s]\n", tmp->line);
		tmp = tmp->next;
	}
}

struct cub3d 		init_env(struct data arg)
{
	struct cub3d 	env;

	ft_bzero(&env, sizeof(struct cub3d ));
	ft_bzero(&env.ray, sizeof(t_ray));
	get_arg_for_env(&env, arg, 0, 0);
	env.ray.speed = 0.1;
	// printer_map(&arg);
	if (!(env.map = from_lst_to_tab(arg.map)))
	{
		env.error = FROM_LST_ERROR;
		ft_error(env.error, &env);
	}
	init_env_2(&env, arg);
	// init_env_orientation(&env);
	init_tex(&env);
	env.map_height = ft_lstsize_map(env.arg.map);
	if ((env.error = init_raybuffer(&env)) != SUCCESS)
	{
		ft_error(env.error, &env);
	}
	return (env);
}
