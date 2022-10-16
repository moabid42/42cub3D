/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:15:57 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 16:51:43 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			launch_env(struct data arg, int ac)
{
	struct cub3d 	env;

	if (check_map(arg.map, 0, 0) != SUCCESS)
		return (MAP_ERROR);
	env = init_env(arg);
	if (ac == 3)
		env.save_flag = 1;
	events(env);
	return (true);
}

bool	cub3d_create(struct data *arg, char *file)
{
	int			fd1;
	int			ret;
	char		*buff;
	
	ret = 0;
	buff = NULL;
	fd1 = open(file, O_RDWR);
	while ((ret = get_next_line(fd1, &buff)) > 0)
	{
		if (fetch_arguments(arg, buff) != SUCCESS)
			return (ARGUMENT_ERROR);
		free(buff);
	}
	if (buff)
		free(buff);
	if (ret == -1)
		return (ft_error_arg(FILE_READ_ERROR));
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
