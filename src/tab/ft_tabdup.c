/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 01:26:19 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:34:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char *tab[])
{
	char	**copy;
	size_t	size;
	size_t	i;

	copy = NULL;
	size = 0;
	i = 0;
	size = ft_tabsize(tab);
	copy = malloc(sizeof(char *) * (size + 1));
	if (copy) {
		while (i < size) {
			copy[i] = ft_strdup(tab[i]);
			if (!copy[i]) {
				ft_freetab(copy);
				return (NULL);
			}
			++i;
		}
		copy[i] = NULL;
	}
	return (copy);
}
