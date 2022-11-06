/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:49:29 by phperrot          #+#    #+#             */
/*   Updated: 2022/11/06 17:31:16 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*output;
	int		i;
	int		size;

	if (!s1)
	{
		return (NULL);
	}
	size = ft_strlen(s1);
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (0);
	if (output == NULL)
		return (NULL);
	i = 0;
	while ((char)s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
