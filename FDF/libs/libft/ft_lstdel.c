/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:40:59 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/06 16:35:24 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		p = *alst;
		*alst = (*alst)->next;
		(*del)(p->content, p->content_size);
		free(p);
	}
	*alst = NULL;
}
