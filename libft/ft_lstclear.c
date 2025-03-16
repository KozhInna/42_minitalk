/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:43:04 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/23 11:23:44 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *node;
    t_list *temp;

    if (!lst || !del)
        return ;
    node = *lst;
    while (node)
    {
        del(node->content);
        temp = node->next;
        free(node);
        node = temp;
    }
    *lst = NULL;
}