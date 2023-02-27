/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 01:25:45 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:24:48 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	if (!src || !dest) {
		return (NULL);
	}
	i = 0;
	while (dest[i]) {
		++i;
	}
	j = 0;
	while (src[j]) {
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = 0;
	return (dest);
}
