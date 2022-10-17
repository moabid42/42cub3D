/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:21 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/17 00:38:21 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_map(struct data *arg, char *line)
{
	t_map	*tmp;

	if (!(tmp = ft_lstnew_map(ft_strdup(line))))
		return (ERROR);
	ft_lstadd_back_map(&(arg->map), tmp);
	// printf("The content of the map is: %s\n", tmp->line);
	return (SUCCESS);
}

int			check_floor_ceil_b(struct data *arg, char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]) && line[i] != '-')
		i++;
	if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
		return (RGB_ERROR);
	if (line[0] == 'F')
		arg->floor.b = ft_atoi(line + i);
	else
		arg->ceil.b = ft_atoi(line + i);
	return (SUCCESS);
}

int			check_floor_ceil(struct data *arg, char *line)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]) && line[i] != '-')
		i++;
	if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
		return (RGB_ERROR);
	if (line[0] == 'F')
		arg->floor.r = ft_atoi(line + i);
	else
		arg->ceil.r = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]) && line[i] != '-')
		i++;
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

int			fetch_arguments(struct data *arg, char *line)
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
		if (get_map(arg, line) != SUCCESS)
		{
			ft_putstr("Error\nProblems with map");
			return (MAP_ERROR);
		}
	// printf("The character is %c\n", line[0]);
	// if (!ft_isdigit(line[0]) && !ft_strchr("RNSEWSFC", line[0]))
	// 	return (ft_error_arg(UNKNOW_ARG));
	return (SUCCESS);
}
