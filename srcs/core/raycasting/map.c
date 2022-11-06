/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:13:47 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 20:20:33 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_same_size(struct s_map *map)
{
	int				size;
	struct s_map	*tmp;

	tmp = map;
	size = (int)ft_strlen(tmp->line);
	while (tmp)
	{
		if ((int)ft_strlen(tmp->line) != size)
			return (ERROR);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	check_nsm(struct s_map *tmp, struct s_map *previous, int i, int j)
{
	struct s_map	*next;

	tmp = tmp->next;
	next = tmp->next;
	while (tmp->next)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] != '1' && tmp->line[i] != ' ' && i >= \
			(int)ft_strlen(previous->line))
				return (MAP_ERROR_NOT_CLOSED);
			if (next)
				if (tmp->line[i] != '1' && tmp->line[i] != ' ' && i >= \
				(int)ft_strlen(next->line))
					return (MAP_ERROR_NOT_CLOSED);
			i++;
		}
		previous = tmp;
		tmp = tmp->next;
		next = tmp->next;
		j++;
	}
	return (SUCCESS);
}

int	check_map_closed(struct s_map *map)
{
	int				i;
	struct s_map	*tmp;

	tmp = map;
	if (check_nsm(tmp, tmp, 0, 1) != SUCCESS)
		return (MAP_ERROR_NOT_CLOSED);
	i = 0;
	while (tmp->line[i])
	{
		if (tmp->line[i++] != '1')
			return (MAP_ERROR_NOT_CLOSED);
	}
	while (tmp->next)
	{
		if (tmp->line[0] != '1')
			return (MAP_ERROR_NOT_CLOSED);
		if (tmp->line[ft_strlen(tmp->line) - 1] != '1')
			return (MAP_ERROR_NOT_CLOSED);
		tmp = tmp->next;
	}
	i = 0;
	while (tmp->line[i])
		if (tmp->line[i++] != '1')
			return (MAP_ERROR_NOT_CLOSED);
	return (SUCCESS);
}

int	check_map(struct s_map *map, int count_pos, int i)
{
	struct s_map	*tmp;

	tmp = map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (!ft_strchr("012NSWE", tmp->line[i]))
				return (ft_error_arg(MAP_ERROR_WRONG_CHAR));
			if (ft_strchr("NSWE", tmp->line[i]))
				count_pos++;
			if (count_pos > 1)
				return (ft_error_arg(MAP_ERROR_MANY_POS));
			i++;
		}
		tmp = tmp->next;
	}
	if (!count_pos)
		return (ft_error_arg(MAP_ERROR_NO_POS));
	if (check_map_closed(map) != SUCCESS)
		return (ft_error_arg(MAP_ERROR_NOT_CLOSED));
	return (SUCCESS);
}
