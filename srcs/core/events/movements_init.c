/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:19:27 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 20:01:36 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	translation(struct s_cub3d *env)
{
	if (env->move_flag & 16)
		right_translation(env);
	if (env->move_flag & 32)
		left_translation(env);
}

void	linear_movement(struct s_cub3d *env)
{
	if (env->move_flag & 1)
		move_up(env);
	if (env->move_flag & 2)
		move_down(env);
}

void	movements_create(struct s_cub3d *env)
{
	if (env->move_flag & 1 || env->move_flag & 2)
		linear_movement(env);
	if (env->move_flag & 32 || env->move_flag & 16)
		translation(env);
	if (env->move_flag & 4)
		rotation(env, -1);
	if (env->move_flag & 8)
		rotation(env, 1);
}
