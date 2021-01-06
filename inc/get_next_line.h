/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:17:42 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/06 03:00:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# define BUFFER_SIZE 4097

typedef struct	s_tab
{
	int		fd;
	int		ret;
	size_t	size;
}				t_tab;

int				get_next_line(int fd, char **line);
void			ft_bufcpy(char *buf);

#endif
