/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:21 by phperrot          #+#    #+#             */
/*   Updated: 2022/11/06 18:04:16 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_map(struct s_data *arg, char *line)
{
	struct s_map 	*tmp;

	if (!(tmp = ft_lstnew_map(ft_strdup(line))))
		return (ERROR);
	ft_lstadd_back_map(&(arg->map), tmp);
	return (SUCCESS);
}

int			check_floor_ceil_b(struct s_data *arg, char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]) && line[i] != '-' && line[i])
		i++;
	if (!line[i])
		return (RGB_ERROR);
	if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
		return (RGB_ERROR);
	if (line[0] == 'F')
		arg->floor.b = ft_atoi(line + i);
	else
		arg->ceil.b = ft_atoi(line + i);
	return (SUCCESS);
}

int			check_floor_ceil(struct s_data *arg, char *line)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]) && line[i] != '-' && line[i])
		i++;
	if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
		return (RGB_ERROR);
	if (line[0] == 'F')
		arg->floor.r = ft_atoi(line + i);
	else
		arg->ceil.r = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]) && line[i] != '-' && line[i])
		i++;
	if (!line[i])
		return (RGB_ERROR);
	if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
		return (RGB_ERROR);
	if (line[0] == 'F')
		arg->floor.g = ft_atoi(line + i);
	else
		arg->ceil.g = ft_atoi(line + i);
	if (check_floor_ceil_b(arg, line, i) != SUCCESS)
		return (RGB_ERROR);
	return (SUCCESS);
}

int			fetch_arguments(struct s_data *arg, char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		return (SUCCESS);
	arg->screen_w = WIDTH;
	arg->screen_h = HEIGHT;
	if (ft_strchr("NSWE", line[0]))
	{
		if (check_path(arg, line) != SUCCESS)
			return (ft_error_arg(PATH_ERROR));
	}
	if (ft_strchr("FC", line[0]))
		if (check_floor_ceil(arg, line) != SUCCESS)
			return (ft_error_arg(RGB_ERROR));
	if (ft_isdigit(line[0]) || line[0] == ' ')
	{
		arg->map_flag = 1;
		if (get_map(arg, line) != SUCCESS)
		{
			ft_putstr("Error\nProblems with map");
			return (MAP_ERROR);
		}
	}
	return (SUCCESS);
}
