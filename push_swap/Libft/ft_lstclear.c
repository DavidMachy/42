/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:23:31 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 08:45:37 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *nxt;

	if (del == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		nxt = tmp->next;
        del((tmp)->content);
        free(tmp);
		tmp = nxt;
	}
	*lst = NULL;
}