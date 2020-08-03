/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:09:00 by adbenoit          #+#    #+#             */
/*   Updated: 2019/11/14 15:54:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned long int	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start - 1)
	{
		if (!(str = malloc(sizeof(char) * (ft_strlen(s) - start + 1))))
			return (NULL);
	}
	else
	{
		if (!(str = malloc(sizeof(char) * (len + 1))))
			return (NULL);
	}
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
