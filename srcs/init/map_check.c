/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:59:14 by moabid            #+#    #+#             */
/*   Updated: 2022/11/07 03:03:50 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	first_line_checker(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	last_line_checker(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	line_checker(char *prev_line, char *line, char *next_line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] == '0')
		{
			if (line[j + 1] == ' ' || line[j - 1] == ' '
				|| prev_line[j] == ' ' || next_line[j] == ' ')
				return (false);
		}
		j++;
	}
	return (true);
}

void	init_vars(struct s_map **map, struct s_map **tmp,
					struct s_map **prev_line, struct s_map **next_line)
{
	*tmp = *map;
	if ((*tmp)->next)
		*next_line = (*tmp)->next;
	*prev_line = *map;
}

bool	cub3d_check_map(struct s_map *map, int i)
{
	struct s_map	*tmp;
	struct s_map	*prev_line;
	struct s_map	*next_line;

	init_vars(&map, &tmp, &prev_line, &next_line);
	while (tmp != NULL)
	{
		if (i == 0 && first_line_checker(tmp->line) == false)
			return (error(INVALID_LINE));
		else if (tmp->next == NULL)
		{
			if (last_line_checker(tmp->line) == false)
				return (error(INVALID_LINE));
		}
		else if (!line_checker(prev_line->line, tmp->line, next_line->line))
			return (error(INVALID_LINE));
		prev_line = tmp;
		tmp = tmp->next;
		if (tmp)
			next_line = tmp->next;
		i++;
	}
	return (true);
}
