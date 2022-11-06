/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:56:05 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 18:04:16 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cub3d_create(struct s_data *arg, char *file)
{
	int			fd1;
	int			ret;
	char		*line;
	
	ret = 0;
	fd1 = open(file, O_RDWR);
	line = get_next_line(fd1);
	arg->line_index = 0;
	arg->map_flag = 0;
	while (line)
	{
		if (ft_strchr(line, '\n'))
		{
			if (line_isnotempty(arg, line) == false)
				return (ft_error_arg(FILE_READ_ERROR));
			new_line_remove(line);
		}
		if (fetch_arguments(arg, line) != SUCCESS)
			return (ARGUMENT_ERROR);
		free(line);
		line = get_next_line(fd1);
		arg->line_index++;
	}
	return (true);
}
