/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:57:54 by amercier          #+#    #+#             */
/*   Updated: 2026/01/16 16:40:40 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game game)
{
	free_map(&game.map);
}


void	free_map(t_map *map)
{
	int	y;

	if (!map->matrix)
		return;
	y = 0;
	while (y < map->height)
	{
		free(map->matrix[y]);
		y++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

void	free_rows(t_list **rows, char *row)
{
	ft_lstclear(rows, free);
	free(row);
}
