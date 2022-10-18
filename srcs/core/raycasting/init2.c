/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:09:40 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/18 16:37:57 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	inline	from_rgb_to_hex(struct s_rgb  color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}

void		player_create(struct cub3d *env, struct data arg, int y, int x)
{
	struct s_map 	*tmp;

	tmp = arg.map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x] != '\0')
		{
			if (ft_strchr("NSWE", tmp->line[x]))
			{
				env->orientation = tmp->line[x];
				env->player_x = x++;
				env->player_y = y++;
			}
			x++;
		}
		tmp = tmp->next;
		y++;
	}
}
