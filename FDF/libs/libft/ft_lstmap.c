/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:02:00 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 19:12:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*q;
	t_list	*new;

	p = lst;
	new = NULL;
	q = NULL;
	while (p)
	{
		new = ft_lstnew(p->content, p->content_size);
		ft_lstadd2(&q, (*f)(new));
		p = p->next;
	}
	return (q);
}
