/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:58:30 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:28:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char		*str;

	if (s == NULL || f == NULL) {
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str) {
		i = 0;
		while (s[i]) {
			str[i] = f(i, s[i]);
			++i;
		}
		str[i] = 0;
	}
	return (str);
}
