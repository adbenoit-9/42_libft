/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:40:10 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:12:38 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;

	size = 0;
	if (n < 0) {
		++size;
		n *= -1;
	}
	while (n >= 10) {
		++size;
		n = n / 10;
	}
	++size;
	if (n == -2147483648) {
		size = 11;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	neg;
	size_t	size;
	size_t	num;

	size = get_size(n);
	neg = 0;
	nb = malloc(sizeof(char) * (size + 1));
	if (!nb) {
		return (0);
	}
	if (n < 0) {
		nb[0] = '-';
		num = -n;
		neg = 1;
	}
	else {
		num = n;
	}
	nb[size] = 0;
	while (size > neg) {
		nb[size-- - 1] = num % 10 + 48;
		num = num / 10;
	}
	return (nb);
}
