/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 01:27:26 by adbenoit          #+#    #+#             */
/*   Updated: 2023/02/27 17:33:53 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, int fd)
{
	size_t	i;

	i = 0;
	while (tab[i]) {
		ft_putendl_fd(tab[i], fd);
		++i;
	}
	return ;
}
