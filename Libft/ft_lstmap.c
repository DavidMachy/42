/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:56:15 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 09:42:41 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst->content));
    if (new == NULL)
        return (0);
    lst = lst->next;
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
        {
            ft_lstclear(&new, del);
            return (NULL);
        }
        ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}