/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:35:36 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:13:51 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0) {
		ft_putchar_fd('0', fd);
	}
	else if (n == -2147483648) {
		ft_putstr_fd("-2147483648", fd);
	}
	else {
		if (n < 0) {
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n > 0) {
			if (n / 10 != 0) {
				ft_putnbr_fd(n / 10, fd);
			}
			ft_putchar_fd(n % 10 + 48, fd);
		}
	}
}
