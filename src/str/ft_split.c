/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:49:10 by adbenoit          #+#    #+#             */
/*   Updated: 2021/10/09 20:10:20 by adbenoit         ###   ########.fr       */
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
	size_t	i[3];

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_countrow(s, c) + 1));
	i[0] = 0;
	i[1] = -1;
	while (tab && ++i[1] < ft_countrow(s, c))
	{
		while (s[i[0]] == c && s[i[0]])
			++i[0];
		tab[i[1]] = malloc(sizeof(char) * (ft_size(s, c, i[0]) + 1));
		if (!tab[i[1]])
			return (ft_freetab(tab));
		i[2] = -1;
		--i[0];
		while (s[++i[0]] != c && s[i[0]])
			tab[i[1]][++i[2]] = s[i[0]];
		tab[i[1]][i[2] + 1] = 0;
	}
	if (tab)
		tab[i[1]] = 0;
	return (tab);
}
