/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:09:00 by adbenoit          #+#    #+#             */
/*   Updated: 2021/10/09 20:00:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = len + 1;
	if (len > ft_strlen(s) - start - 1)
		size = ft_strlen(s) - start + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		++i;
		++start;
	}
	str[i] = 0;
	return (str);
}
