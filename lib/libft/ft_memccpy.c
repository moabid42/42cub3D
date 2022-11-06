/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:43:58 by phperrot          #+#    #+#             */
/*   Updated: 2022/11/06 17:20:59 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*point_dst;
	unsigned char		*point_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	point_dst = (unsigned char *)dst;
	point_src = (unsigned char *)src;
	while (i < n)
	{
		point_dst[i] = point_src[i];
		if (point_src[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
