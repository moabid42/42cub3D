/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:10:27 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 18:10:30 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_conv(const char *str, char conversion_type)
{
	int				i;
	int				sign;
	unsigned long	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((char)str[i] == '\n' | (char)str[i] == '\r' | (char)str[i] == '\t'
		| (char)str[i] == '\f' | (char)str[i] == '\v' | (char)str[i] == ' ')
		i++;
	if ((char)str[i] == '+' && (char)str[i + 1] != '-')
		i++;
	if ((char)str[i] == '-')
		sign = -sign;
	if ((char)str[i] == '-')
		i++;
	while (((char)str[i] - '0') >= 0 && ('9' - (char)str[i]) >= 0)
	{
		nb = (nb * 10 + ((char)str[i] - '0'));
		i++;
	}
	if (ft_strchr("puxX", conversion_type) > 0)
		return (nb * sign);
	else
		return ((int)(nb * sign));
}
