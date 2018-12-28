/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:54:46 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 18:26:34 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *src)
{
	t_list	*p;
	t_list	*d;

	p = src;
	d = NULL;
	while (p)
	{
		ft_lstadd2(&d, ft_lstnew(p->content, p->content_size));
		p = p->next;
	}
	return (d);
}
