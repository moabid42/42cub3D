/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:20:03 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 19:20:05 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *str, int start, int len)
{
	int					i;
	char				*output;

	i = 0;
	if (!str)
		return (NULL);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	while (i < len && (str[start + i] != '\n'))
	{
		output[i] = str[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
