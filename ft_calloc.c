/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:48:24 by adbenoit          #+#    #+#             */
/*   Updated: 2019/11/16 16:50:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char				*mem;
	unsigned long int	i;

	if (!(mem = (char *)malloc(count * size)))
		return (0);
	i = 0;
	ft_bzero(mem, count * size);
	return ((void *)mem);
}
