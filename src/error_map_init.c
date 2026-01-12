/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:37:49 by amercier          #+#    #+#             */
/*   Updated: 2026/01/12 12:09:36 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_error errcode)
{
	ft_printf("Error\n");
	if (errcode == ERR_MAP_SHAPE)
		ft_printf("Wrong map shape.");
	if (errcode == ERR_ALLOC)
		perror("Failed memory allocation");
	if (errcode == ERR_MAP_UNCOMPLETE)
		ft_printf("Map missing player, coin or exit.");
	if (errcode == ERR_MAP_INIT)
		ft_printf("Map initialisation failed. Must be enclosed.\
				Must contain the following characters '01CEP'.\n\
				Cannot contain more than 1 E or P");
}
