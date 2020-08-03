/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:40:10 by adbenoit          #+#    #+#             */
/*   Updated: 2019/11/11 14:12:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_size1(int n)
{
	unsigned int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	size++;
	if (n == -2147483648)
		size = 11;
	return (size);
}

char			*ft_itoa(int n)
{
	char			*nb;
	unsigned int	neg;
	unsigned int	size;
	unsigned int	num;

	size = ft_size1(n);
	neg = 0;
	if (!(nb = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
	{
		nb[0] = '-';
		num = -n;
		neg = 1;
	}
	else
		num = n;
	nb[size] = 0;
	while (size > neg)
	{
		nb[size - 1] = num % 10 + 48;
		num = num / 10;
		size--;
	}
	return (nb);
}
