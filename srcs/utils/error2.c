/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:40:52 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 19:40:54 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error_tex_inputs(int error, char *orientation)
{
	error = ft_strlen(orientation);
	free(orientation);
	ft_putstr("Error\nWrong texture path");
	return (ERROR);
}

void	ft_error_arg2(int error)
{
	if (error == MAP_ERROR_NOT_CLOSED)
		ft_putstr("Error\nMap not closed");
	if (error == MAP_ERROR_SAME_SIZE)
		ft_putstr("Error\nAll lines of the map are not the same size");
	if (error == UNKNOW_ARG)
		ft_putstr("Error\nUnknown arg");
}

int		ft_error_arg(int error)
{
	if (error == FILE_EXT_ERROR)
		ft_putstr("Error\nFirst argument is not a .cub file");
	if (error == SAVE_FLAG_ERROR)
		ft_putstr("Error\nNot a valid flag");
	if (error == FILE_READ_ERROR)
		ft_putstr("Error\nCould not complete file reading");
	if (error == SCREEN_ERROR)
		ft_putstr("Error\nWrong screen dimensions");
	if (error == PATH_ERROR)
		ft_putstr("Error\nWrong texture path");
	if (error == RGB_ERROR)
		ft_putstr("Error\nProblems with floor or ceil");
	if (error == MAP_ERROR_WRONG_CHAR)
		ft_putstr("Error\nInvalid character in the map");
	if (error == MAP_ERROR_MANY_POS)
		ft_putstr("Error\nSeveral positions entered in the map");
	if (error == MAP_ERROR_NO_POS)
		ft_putstr("Error\nNo position was entered in the map");
	if (error)
		exit(1);
	ft_error_arg2(error);
	return (ERROR);
}
