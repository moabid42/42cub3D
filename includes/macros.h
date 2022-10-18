/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:24:51 by moabid            #+#    #+#             */
/*   Updated: 2022/10/18 13:21:39 by moabid           ###   ########.fr       */
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
	OPEN_ERROR,
	WRITE_ERROR,
	FROM_LST_ERROR,
	MAP_ERROR,
	MAP_ERROR_WRONG_CHAR,
	MAP_ERROR_MANY_POS,
	MAP_ERROR_NO_POS,
	MAP_ERROR_NOT_CLOSED,
	MAP_ERROR_SAME_SIZE,
	MALLOC_ERROR,
	IMG_ERROR,
	IMG_ERROR_WEAPON_1,
	IMG_ERROR_WEAPON_2,
	IMG_ERROR_WEAPON_3,
	IMG_ERROR_WEAPON_4,
	IMG_ERROR_WEAPON_5,
	IMG_ERROR_ITEM,
	TEX_ERROR_N,
	TEX_ERROR_S,
	TEX_ERROR_W,
	TEX_ERROR_E,
	TEX_ERROR_SP,
	TEX_ERROR_SP1,
	TEX_ERROR_D,
	TEX_ERROR_B,
	TEX_ERROR_A,
	TEX_ERROR_T,
	TEX_ERROR_E1,
	TEX_ERROR_E2,
	TEX_ERROR_E3,
	TEX_ERROR_E4,
	TEX_ERROR_E5,
	TEX_ERROR_E6,
	TEX_ERROR_E7,
	TEX_ERROR_E8,
	TEX_ERROR_E9,
	TEX_ERROR_ENNEMY,
	MLX_ERROR,
	TEX_ERROR,
	PIXEL_ERROR,
	COLOR_ERROR,
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
#	define SPACE_BAR 49
#	define KEY_EXIT 53
#	define STRUCTURENOTIFYMASK 10001
#	define MINIMAP_SIZE 6
#	define COMPRESSION 24
#	define BYTES_PER_PIX 3
#	define SCREEN_MAX_HEIGHT 1440
#	define SCREEN_MAX_WIDTH 2560

#	define SPEED	0.1
#	define ROTATION_SPEED 0.1

#	define HEIGHT 1440
#	define WIDTH 2560


#endif