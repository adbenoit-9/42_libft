/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:49:10 by adbenoit          #+#    #+#             */
/*   Updated: 2021/10/09 19:58:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countrow(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s[0] != c && s[0] != 0)
	{
		++count;
		++i;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			++count;
		++i;
	}
	return (count);
}

static size_t	ft_size(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		++size;
		++i;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_countrow(s, c) + 1));
	if (!tab)
		return (0);
	i = 0;
	k = -1;
	while (++k < ft_countrow(s, c))
	{
		while (s[i] == c && s[i])
			++i;
		tab[k] = malloc(sizeof(char) * (ft_size(s, c, i) + 1));
		if (!tab)
			return (ft_freetab(tab));
		j = -1;
		--i;
		while (s[++i] != c && s[i])
			tab[k][++j] = s[i];
		tab[k][j + 1] = 0;
	}
	tab[k] = 0;
	return (tab);
}
