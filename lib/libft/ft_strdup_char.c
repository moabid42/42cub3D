/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:03:57 by phperrot          #+#    #+#             */
/*   Updated: 2022/11/06 17:32:02 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_char(char c)
{
	char	*output;

	output = malloc(sizeof(char) * 2);
	if (!output)
		return (NULL);
	output[0] = c;
	output[1] = '\0';
	return (output);
}
