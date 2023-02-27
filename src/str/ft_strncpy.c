/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:18:48 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:29 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL) {
		return (dest);
	}
	i = 0;
	while (src[i] && i < n) {
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}
