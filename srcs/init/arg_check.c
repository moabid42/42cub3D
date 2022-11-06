/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:08:46 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 20:07:02 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	line_isnotempty(struct s_data *arg, char *line)
{
	if (arg->map_flag == 1)
		if (line[0] == '\n' && line[1] == '\0')
			return (false);
	return (true);
}

bool	cub3d_arg_check(int ac, char **av)
{
	if (ac > 2 || ac < 2)
		return (error(NB_ARG_ERROR));
	else if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (error(FILE_EXT_ERROR));
	return (true);
}
