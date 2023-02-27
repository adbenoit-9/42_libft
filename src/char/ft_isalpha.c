/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:25:56 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 16:47:51 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	ret;

	ret = 0;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		ret = 1;
	}
	return (ret);
}
