/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:37:49 by amercier          #+#    #+#             */
/*   Updated: 2026/01/19 14:03:51 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_error_map(t_error errcode);

void	print_error(t_error errcode)
{
	ft_putstr_fd("Error\n", 2);
	if (errcode == ERR_ARGS)
		ft_putstr_fd("Wrong number of args\n", 2);
	else if (errcode == ERR_FILENAME)
		ft_putstr_fd("Wrong file format\n", 2);
	else if (errcode == ERR_OPEN)
		perror("Failed openning file");
	else if (errcode == ERR_ALLOC)
		perror("Failed memory allocation");
	else if (errcode == ERR_WIN_SIZE)
		ft_putstr_fd("Map size too large for screen resolution\n"
			"Reduce number of tiles\n", 2);
	else if (errcode == ERR_IMG_LOAD)
		perror("Failed loading image");
	else if (errcode == ERR_IMG_SIZE)
		ft_putstr_fd("Image size doesn't match TILE_SIZE\n", 2);
	else
		print_error_map(errcode);
}

static void	print_error_map(t_error errcode)
{
	if (errcode == ERR_MAP_SHAPE)
		ft_putstr_fd("Wrong map shape\n", 2);
	else if (errcode == ERR_MAP_UNCOMPLETE)
		ft_putstr_fd("Map missing player, coin or exit\n", 2);
	else if (errcode == ERR_MAP_INIT)
		ft_putstr_fd("Map initialisation failed\n"
			"Must be enclosed\n"
			"Allowed characters: {01CEP}\n"
			"Cannot contain more than one 'E' or 'P'\n", 2);
	else if (errcode == ERR_MAP_LAB)
		ft_putstr_fd("At least one of the coins "
			"or the exit is not reachable\n", 2);
}
