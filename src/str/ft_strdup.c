/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:24:01 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:26:38 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i]) {
		++i;
	}
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy) {
		return (0);
	}
	i = 0;
	while (s1[i]) {
		copy[i] = s1[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);
}
