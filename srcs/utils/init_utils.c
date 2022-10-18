/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:58:27 by moabid            #+#    #+#             */
/*   Updated: 2022/10/18 18:25:14 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    new_line_remove(char *line)
{
    int i;
	
    i = 0;
    while (line[i] != '\n')
        i++;
    line[i] = '\0';
}

int	inline	from_rgb_to_hex(struct s_rgb  color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}
