/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:24:51 by moabid            #+#    #+#             */
/*   Updated: 2022/10/18 18:47:17 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "cub3d.h"

typedef	enum				e_error
{
	ERROR,
	INVALID_LINE,
	ZBUFFER_ERROR,
	NB_ARG_ERROR,
	FILE_EXT_ERROR,
	SAVE_FLAG_ERROR,
	FILE_READ_ERROR,
	SCREEN_ERROR,
	ARGUMENT_ERROR,
	PATH_ERROR,
	UNKNOW_ARG,
	RGB_ERROR,
	FROM_LST_ERROR,
	MAP_ERROR,
	MAP_ERROR_WRONG_CHAR,
	MAP_ERROR_MANY_POS,
	MAP_ERROR_NO_POS,
	MAP_ERROR_NOT_CLOSED,
	MAP_ERROR_SAME_SIZE,
	IMG_ERROR,
	TEX_ERROR_N,
	TEX_ERROR_S,
	TEX_ERROR_W,
	TEX_ERROR_E,
	TEX_ERROR,
	PIXEL_ERROR,
	SUCCESS
}							t_error;

#	define INVISI_CHAR "\t\v\r\f "
#	define KEY_UP 13
#	define KEY_RIGHT 2
#	define KEY_LEFT 0
#	define KEY_DOWN 1
#	define ROTATE_LEFT 123
#	define ROTATE_RIGHT 124
#	define KEYPRESS 2
#	define KEYRELEASE 3
#	define KEYPRESSMASK 1
#	define KEYRELEASEMASK 10
#	define KEY_EXIT 53
#	define STRUCTURENOTIFYMASK 10001

#	define SPEED	0.2
#	define ROTATION_SPEED 0.2

#	define HEIGHT 1440
#	define WIDTH 2560

#	define set_flag(flag, bit) (flag |= bit)
#	define unset_flag(flag, bit) (flag &= (~(1 << bit)))

#endif