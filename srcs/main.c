/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:15:57 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 14:02:56 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	launch_env(struct data arg, int ac)
{
	struct cub3d 	env;

	if (cub3d_check_map(arg.map, 0) == false)
		return (false);
	env = env_create(arg);
	if (cub3d_run(env) == false)
		return (false);
	return (true);
}

int			main(int ac, char **av)
{
	struct data	arg;

	ft_bzero(&arg, sizeof(arg));
	if (cub3d_arg_check(ac, av) == true)
		if (cub3d_create(&arg, av[1]) == true)
			return (launch_env(arg, ac));
	return (0);
}
