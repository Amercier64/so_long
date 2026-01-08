/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:37:49 by amercier          #+#    #+#             */
/*   Updated: 2026/01/08 09:59:39 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_error errcode)
{
	if (errcode == ERR_MAP_SHAPE)
		ft_printf("Error\nWrong map shape.");
	if (errcode == ERR_ALLOC);
		perror("Error\nFailed memory allocation");
}

void	*error_map_init(t_list	*lst, void *ptr, t_error errcode)
{
	ft_lstclear(lst, free);
	free(ptr);
	print_error(errcode);
	return (NULL);
}
