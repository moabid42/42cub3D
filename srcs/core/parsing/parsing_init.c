/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:08:46 by moabid            #+#    #+#             */
/*   Updated: 2022/10/17 23:37:08 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool			cub3d_arg_check(int ac, char **av)
{
	int		error;

	error = 0;
	if (ac > 2)
		error = NB_ARG_ERROR_TOO_MANY;
	if (ac < 2)
		error = NB_ARG_ERROR_TOO_FEW;
	if (ac == 2)
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			error = FILE_EXT_ERROR;
	if (error)
	{
		ft_error_arg(error);
		return (false);
	}
	return (true);
}
