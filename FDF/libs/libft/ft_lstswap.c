/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:51:36 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 17:52:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	temp = ft_lstnew((*lst2)->content, (*lst2)->content_size);
	ft_memcpy((*lst2)->content, (*lst1)->content, (*lst1)->content_size);
	(*lst2)->content_size = (*lst1)->content_size;
	ft_memcpy((*lst1)->content, temp->content, temp->content_size);
	(*lst1)->content_size = temp->content_size;
}
