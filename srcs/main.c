/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:15:57 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/17 23:00:42 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	first_line_checker(char *line)
{
	int i;

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
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	printf("The last line is valid\n");
	return (true);
}

bool	line_checker(char *prev_line, char *line, char *next_line)
{
	int j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] == '0')
		{
			// printf("The char is : %c\n", line[j]);
			// printf("The prev char is : %c\n", prev_line[j]);
			// printf("The next char is : %c\n", next_line[j]);
			// printf("----------------------\n");
			if (line[j + 1] == ' ' || line[j - 1] == ' '
				|| prev_line[j] == ' ' || next_line[j] == ' ')
				return (false);
		}
		j++;
	}
	return (true);
}

void	printer_map_2(t_map *map)
{
	t_map *tmp;

	tmp = map;
	while (tmp != NULL)
	{
		printf("[%s]\n", tmp->line);
		tmp = tmp->next;
	}
}

bool			cub3d_check_map(t_map *map)
{
	t_map *tmp;
	t_map *prev_line;
	t_map *next_line;
	int	i;

	i = 0;
	tmp = map;
	if (tmp->next)
		next_line = tmp->next;
	prev_line = map;
	//printer_map_2(map);
	while (tmp != NULL)
	{
		if (i == 0)
		{
			if (first_line_checker(tmp->line) == false)
				{
					printf("The first line is not valid\n");
					return (false);
				}
		}
		else if (tmp->next == NULL)
		{
			if (last_line_checker(tmp->line) == false)
				{
					printf("The last line is not valid\n");
					return (false);
				}
		}
		else
		{
			if (line_checker(prev_line->line, tmp->line, next_line->line) == false)
				{
					printf("The %d line is not valid\n", i + 1);
					return (false);
				}
		}
		prev_line = tmp;
		tmp = tmp->next;
		if (tmp)
			next_line = tmp->next;
		i++;
	}
	return (true);
}
/// @brief ------------------------------>
int			launch_env(struct data arg, int ac)
{
	struct cub3d 	env;

	if (cub3d_check_map(arg.map) == false)
		return (MAP_ERROR);
	env = init_env(arg);
	if (ac == 3)
		env.save_flag = 1;
	events(env);
	return (true);
}
/////////////////*///////////////////////
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
	arg->line_index = 0;
	while (line)
	{
		if (ft_strchr(line, '\n'))
			new_line_remove(line);
		if (fetch_arguments(arg, line) != SUCCESS)
			return (ARGUMENT_ERROR);
		free(line);
		line = get_next_line(fd1);
		arg->line_index++;
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
