/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:48:38 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 08:55:11 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (f == NULL)
        return ;
    while (lst != NULL)
    {
        f(lst->content);
        lst = lst->next;
    }
}