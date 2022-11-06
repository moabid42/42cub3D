/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:04:30 by phperrot          #+#    #+#             */
/*   Updated: 2022/11/06 17:35:41 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char old, char new)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
	return (str);
}
