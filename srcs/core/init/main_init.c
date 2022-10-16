/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:41:21 by moabid            #+#    #+#             */
/*   Updated: 2022/10/16 01:41:43 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main_arg_check(int ac, char **av)
{
	int		error;

	error = 0;
	if (ac > 3)
		error = NB_ARG_ERROR_TOO_MANY;
	if (ac < 2)
		error = NB_ARG_ERROR_TOO_FEW;
	if (ac == 2)
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			error = FILE_EXT_ERROR;
	if (ac == 3)
		if (ft_strncmp(av[2], "--save", 6) != 0)
			error = SAVE_FLAG_ERROR;
	if (error)
	{
		ft_error_arg(error);
		return (ARGUMENT_ERROR);
	}
	return (SUCCESS);
}

int			launch_env(struct data arg, int ac)
{
	struct cub3d	env;

	if (check_map(arg.map, 0, 0) != SUCCESS)
		return (MAP_ERROR);
	env = init_env(arg);
	if (ac == 3)
		env.save_flag = 1;
	events(env);
	return (SUCCESS);
}
