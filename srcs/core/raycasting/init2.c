/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:09:40 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/16 14:05:15 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			from_rgb_to_hex(t_rgb color)
{
	int		output;

	output = 256 * 256 * color.r + 256 * color.g + color.b;
	printf("The output color is : %d\n", output);
	return (output);
}

void		get_arg_for_env(struct cub3d *env, struct data arg, int y, int x)
{
	t_map	*tmp;

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
		env->map_width = x;
		tmp = tmp->next;
		y++;
	}
	env->map_height = y - 1;
}

t_img		*ft_new_img(struct cub3d *env, char *file)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
	{
		return (NULL);
	}
	if (!(img->img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, file,
		&img->width, &img->height)))
	{
		free(img);
		return (NULL);
	}
	if (!(img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian)))
	{
		free(img->img_ptr);
		free(img);
		return (NULL);
	}
	return (img);
}