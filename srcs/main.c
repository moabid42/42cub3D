/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:15:57 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 17:59:50 by moabid           ###   ########.fr       */
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

void    new_line_remove(char *line)
{
    int i;
	
    i = 0;
    while (line[i] != '\n')
        i++;
    line[i] = '\0';
}

bool	cub3d_create(struct data *arg, char *file)
{
	int			fd1;
	int			ret;
	char		*line;
	
	ret = 0;
	fd1 = open(file, O_RDWR);
	line = get_next_line(fd1);
	while (line)
	{
		new_line_remove(line);
		if (fetch_arguments(arg, line) != SUCCESS)
			return (ARGUMENT_ERROR);
		free(line);
		line = get_next_line(fd1);
	}
	if (line)
		free(line);
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
