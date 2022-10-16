/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:15:57 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 01:55:27 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int			main(int ac, char **av)
// {
// 	int				fd1;
// 	int				ret;
// 	char			*buff;
// 	struct	data	arg;

// 	ft_bzero(&arg, sizeof(arg));
// 	ret = 0;
// 	buff = NULL;
// 	if (main_arg_check(ac, av) != SUCCESS)
// 		return (0);
// 	fd1 = open(av[1], O_RDWR);
// 	while ((ret = get_next_line(fd1, &buff)) > 0)
// 	{
		// if (fetch_arguments(&arg, buff) != SUCCESS)
// 			return (ARGUMENT_ERROR);
// 		free(buff);
// 	}
// 	if (buff)
// 		free(buff);
// 	if (ret == -1)
// 		return (ft_error_arg(FILE_READ_ERROR));
// 	if (launch_env(arg, ac) != SUCCESS)
// 		return (MAP_ERROR);
// 	return (0);
// }



bool    cub3d_create(struct cub3d *cub3d, char **argv)
{
	if (cub3d_map_create(cub3d, argv[1]) == true)
	{
		// if (cub3d_mlx_create(cub3d) == true)
		 	return (true);
		// cub3d_player_destroy(&player);
	}
	// cub3d_map_destroy(cub3d);
	return (false);
}

int main(int argc, char **argv)
{
    struct cub3d cub3d;
	struct data data;

    if (cub3d_create(&cub3d, argv) == true)
		if (launch_env(data, argc) != SUCCESS)
			return (MAP_ERROR);
    // cub3d_destroy(&cub3d);
    return (0);
}