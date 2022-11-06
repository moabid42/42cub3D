/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:19:17 by moabid            #+#    #+#             */
/*   Updated: 2022/11/06 19:48:56 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_char(unsigned long n, char *s, int i, int negative)
{
	unsigned long	tmp;

	i--;
	if (negative)
		s[0] = '-';
	tmp = n;
	if (tmp >= 10)
	{
		ft_fill_char((tmp / 10), s, i, negative);
		s[i] = ((tmp % 10) + '0');
	}
	else
		s[i] = (tmp + '0');
	return (s);
}

static int	ft_size(unsigned long n, int negative)
{
	int				size;
	unsigned long	tmp;

	size = 0;
	if (negative)
		size++;
	tmp = n;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

// static int	ft_negative(long n)
// {
// 	if (n < 0)
// 		return (1);
// 	return (0);
// }

// static int	is_minus(long n)
// {
// 	if (n < 0)
// 		return (-n);
// 	return (n);
// }

int	norm(char **number)
{
	*number = (char *)malloc(sizeof(*number) * 1);
	if (!number)
		return (0);
	return (1);
}

void	ft_neg_min(int *negative, unsigned long *n, int input)
{
	if (input < 0)
		*n = input * -1;
	if (input < 0)
		*negative = 1;
	else
		*negative = 0;
}

char	*ft_itoa_long(long input)
{
	int				size;
	char			*number;
	int				negative;
	unsigned long	n;

	ft_neg_min(&negative, &n, input);
	if (!n)
		return (ft_strdup("0"));
	size = ft_size(n, negative);
	if (n == 0)
	{
		if (norm(&number))
			return (NULL);
		number[0] = '0';
	}
	else
	{
		number = (char *)malloc(sizeof(*number) * size + 1);
		if (!number)
			return (NULL);
		number = ft_fill_char(n, number, size, negative);
	}
	number[size] = '\0';
	return (number);
}
