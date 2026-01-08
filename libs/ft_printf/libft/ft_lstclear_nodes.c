/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:57 by amercier          #+#    #+#             */
/*   Updated: 2026/01/05 14:59:22 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_nodes(t_list **lst)
{
	t_list	*next;

	if (lst == NULL)
		return;
	while(*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
