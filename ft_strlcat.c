/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:20:36 by adbenoit          #+#    #+#             */
/*   Updated: 2019/11/12 18:24:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;
	unsigned long	l;

	i = ft_strlen(dst);
	k = i;
	l = ft_strlen(src);
	j = 0;
	while (src[j] && i < dstsize - 1 && dstsize)
		dst[i++] = src[j++];
	if (dstsize > k)
	{
		dst[i] = 0;
		return (l + k);
	}
	else
		return (l + dstsize);
}
