/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:42:50 by amercier          #+#    #+#             */
/*   Updated: 2025/11/03 11:37:38 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
	else
	{
		ft_lstclear(&((*lst)->next), del);
		ft_lstclear(lst, del);
	}
}
