/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:14:00 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 20:26:54 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	*ft_new_tex(struct s_cub3d *env, char *file, char *type)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	if (!tex)
		return (NULL);
	tex->tex_ptr = mlx_xpm_file_to_image(env->mlx_ptr, file,
			&tex->width, &tex->height);
	if (!tex->tex_ptr)
	{
		free(tex);
		return (NULL);
	}
	tex->tex_data = (int *)mlx_get_data_addr(tex->tex_ptr, &tex->bpp,
			&tex->size_line, &tex->endian);
	if (!tex->tex_data)
	{
		free(tex->tex_ptr);
		free(tex);
		return (NULL);
	}
	return (tex);
}

void	init_tex_wall_sprite(struct s_cub3d *env)
{
	env->tex_n = ft_new_tex(env, env->arg.no, "NO");
	if (env->tex_n == NULL)
		env->error = TEX_ERROR_N;
	env->tex_s = ft_new_tex(env, env->arg.so, "SO");
	if (env->tex_s == NULL)
		env->error = TEX_ERROR_S;
	env->tex_w = ft_new_tex(env, env->arg.we, "WE");
	if (env->tex_w == NULL)
		env->error = TEX_ERROR_W;
	env->tex_e = ft_new_tex(env, env->arg.ea, "EA");
	if (env->tex_e == NULL)
		env->error = TEX_ERROR_E;
}

int	texture_init(struct s_cub3d *env)
{
	env->error = 0;
	init_tex_wall_sprite(env);
	if (env->error)
	{
		env->error = TEX_ERROR;
		ft_error(env->error, env);
	}
	return (SUCCESS);
}
