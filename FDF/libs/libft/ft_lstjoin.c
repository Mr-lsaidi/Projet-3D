/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:50:02 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 18:22:19 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstjoin(t_list *lst1, t_list *lst2)
{
	t_list	*result;
	t_list	*p;

	result = NULL;
	if (!lst1 && lst2)
		return (ft_lstdup(lst2));
	else if (lst1 && !lst2)
		return (ft_lstdup(lst1));
	else if (lst1 && lst2)
	{
		p = lst1;
		while (p)
		{
			ft_lstadd2(&result, ft_lstnew(p->content, p->content_size));
			p = p->next;
		}
		p = lst2;
		while (p)
		{
			ft_lstadd2(&result, ft_lstnew(p->content, p->content_size));
			p = p->next;
		}
	}
	return (result);
}
