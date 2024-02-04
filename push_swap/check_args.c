/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:22:20 by marvin            #+#    #+#             */
/*   Updated: 2023/07/15 23:22:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int strcmp_plus(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (s1[i] == '+' && s2[j] != '+')
        i++;
    else if (s2[j] == '+')
        j++;
    while (s1[i] && s2[j] && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int is_nbr(char *s)
{
    int i;

    i = 0;
    if ((s[i] == '+' || s[i] == '-') && s[i + 1] != '\0')
        i++;
    while (s[i] && (s[i] >= '0' && s[i] <= '9'))
        i++;
    if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
        return (0);
    return (1);
}

int is_zero(char *s)
{
    int i;

    i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (s[i] && s[i] == '0')
        i++;
    if (s[i])
        return (0);
    return (1);
}

int has_dupli(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 1;
        while (av[j])
        {
            if (i != j && !strcmp_plus(av[i], av[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_args(char **av)
{
    int i;
    int n_zero;

    i = 1;
    n_zero = 0;

    while(av[i])
    {
        if (!is_nbr(av[i]))
            return (0);
        n_zero += is_zero(av[i]);
        i++;
    }
    if (n_zero > 1)
        return (0);
    if (has_dupli(av))
        return (0);
    return (1);
}
