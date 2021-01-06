/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:13 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/06 16:03:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_line(char *buf, size_t *len, t_list **lst)
{
	int		i;
	char	*str;
	t_list	*new;

	i = -1;
	while (buf[++i] && buf[i] != '\n')
		++(*len);
	if (!(str = ft_strndup(buf, i)))
		return (0);
	if (!(new = ft_lstnew(str)))
	{
		free(str);
		return (0);
	}
	ft_lstadd_back(lst, new);
	if (buf[i] == '\n')
		return (1);
	return (-1);
}

static void	ft_put_line(t_list **lst, char **line)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		ft_strcat(*line, (*lst)->content);
		*lst = (*lst)->next;
	}
	ft_lstclear(&tmp, free);
	return ;
}

static int	ft_set_line(char **line, t_tab *tab, t_list **lst, char *buf)
{
	long int		ret;
	int				k;

	while ((ret = read(tab->fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		if (ret < 0 || (k = ft_get_line(buf, &tab->size, lst)) == 0)
			return (-1);
		if (k == 1 || ret == 0)
			break ;
	}
	buf[ret] = 0;
	if ((k = ft_get_line(buf, &tab->size, lst)) == 0)
		return (-1);
	if (ret < BUFFER_SIZE && k == -1)
	{
		if (!((*line) = ft_calloc(sizeof(char), tab->size + 1)))
			return (-1);
		ft_put_line(lst, line);
		buf[0] = 0;
		return (0);
	}
	return (1);
}

static int	ft_err(t_list **lst)
{
	ft_lstclear(lst, free);
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	t_tab			tab;
	static char		buf[BUFFER_SIZE + 1];
	t_list			*lst;
	int				k;

	tab.size = 0;
	tab.fd = fd;
	lst = NULL;
	if (fd < 0)
		return (-1);
	if ((k = ft_get_line(buf, &tab.size, &lst)) == 0)
		return (-1);
	if (k == 1 && buf[0] != 0)
		ft_bufcpy(buf);
	else
	{
		tab.ret = ft_set_line(line, &tab, &lst, buf);
		if (BUFFER_SIZE == 0 || tab.ret == -1)
			return (ft_err(&lst));
		if (tab.ret == 0)
			return (0);
		ft_bufcpy(buf);
	}
	if (!((*line) = ft_calloc(sizeof(char), tab.size + 1)))
		return (ft_err(&lst));
	ft_put_line(&lst, line);
	return (1);
}
