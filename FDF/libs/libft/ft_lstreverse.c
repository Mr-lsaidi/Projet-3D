/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:53:21 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 18:42:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list		*res;
	t_list		*p;

	res = NULL;
	p = *lst;
	while (p)
	{
		ft_lstadd(&res, ft_lstnew(p->content, p->content_size));
		p = p->next;
	}
	*lst = res;
}
