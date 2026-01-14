/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:37:49 by amercier          #+#    #+#             */
/*   Updated: 2026/01/14 15:57:59 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_error errcode)
{
	ft_printf("Error\n");
	if (errcode == ERR_ALLOC)
		perror("Failed memory allocation");
	if (errcode == ERR_MAP_SHAPE)
		ft_printf("Wrong map shape.\n");
	if (errcode == ERR_MAP_UNCOMPLETE)
		ft_printf("Map missing player, coin or exit.\n");
	if (errcode == ERR_MAP_INIT)
		ft_printf("Map initialisation failed.\n"
				"Must be enclosed.\n"
				"Allowed characters: {01CEP}.\n"
				"Cannot contain more than one 'E' or 'P'.\n");
	if (errcode == ERR_MAP_LAB)
		ft_printf("At least one of the coins or the exit is not reachable.\n");
}
