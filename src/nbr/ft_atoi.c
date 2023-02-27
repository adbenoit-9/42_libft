/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:39:46 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:10:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	    || str[i] == '\v' || str[i] == '\f' || str[i] == '\r') {
		++i;
	}
	if (str[i] == '-') {
		sign = -1;
	}
	if (str[i] == '-' || str[i] == '+') {
		++i;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9') {
		num = num * 10 + (str[i] - 48);
		++i;
	}
	num = num * sign;
	return (num);
}
