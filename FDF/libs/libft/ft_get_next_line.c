/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:06:25 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/28 23:55:13 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_fd(t_list *lst, const int fd)
{
	t_list *p;

	p = lst;
	while (p && p->content_size != (size_t)fd)
		p = p->next;
	if (p)
		return (p->content_size == (size_t)fd);
	return (0);
}

int		ft_get_next_line(const int fd, char **line)
{
	static	t_list	*list;
	int				ret;
	t_list			*p;

	ret = -1;
	if (fd < 0 || !line || fd > 4096 || BUFF_SIZE <= 0)
		return (-1);
	if (!list)
		list = ft_lstnew("", fd);
	else if (list && !ft_find_fd(list, fd))
		ft_lstadd(&list, ft_lstnew("", fd));
	p = list;
	while (p && p->content_size != (size_t)fd)
		p = p->next;
	if ((p && (ret = ft_fill_list(&p, line, &ret))) && ret)
		return (ret);
	ret = ft_new_line(&p, line);
	return (ret);
}

int		ft_fill_list(t_list **ls, char **line, int *ret)
{
	char		buffer[BUFF_SIZE + 1];
	int			n;

	n = -1;
	if (*ls)
	{
		if ((*line = ft_process_str((*ls)->content, ret)) && (*ret == 1))
		{
			(*ls)->content = ft_strdup(ft_strchr((*ls)->content, '\n') + 1);
			return (1);
		}
		while ((n = read((*ls)->content_size, buffer, BUFF_SIZE)) > 0)
		{
			buffer[n] = '\0';
			(*ls)->content = ft_strjoin((*ls)->content, buffer);
			if ((*line = ft_process_str((*ls)->content, ret)) && (*ret == 1))
			{
				(*ls)->content = ft_strdup(ft_strchr((*ls)->content, '\n') + 1);
				return (1);
			}
		}
	}
	return ((n == -1) ? -1 : 0);
}

int		ft_new_line(t_list **lst, char **line)
{
	int		ret;

	ret = 1;
	if ((*lst))
	{
		*line = ft_process_str((*lst)->content, &ret);
		if (ret == 1)
			(*lst)->content = ft_strdup(ft_strchr((*lst)->content, '\n') + 1);
		else if (ret == -1)
			(*lst)->content = "";
	}
	return ((ret == 1 || ret == -1) ? 1 : 0);
}

char	*ft_process_str(char *str, int *ret)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*ret = 1;
			return (ft_strsub(str, 0, i));
		}
		i++;
	}
	if (i == 0)
		*ret = 0;
	else if (i && str[i - 1] && !str[i])
		*ret = -1;
	return (str);
}
