/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:57:54 by amercier          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:42 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	int	i;

	free_map(&game->map);
	i = 0;
	while (i < IMG_COUNT)
	{
		if (game->data.img[i])
			mlx_destroy_image(game->data.mlx, game->data.img[i]);
		i++;
	}
	if (game->data.win)
		mlx_destroy_window(game->data.mlx, game->data.win);
	if (game->data.mlx)
		mlx_destroy_display(game->data.mlx);
	free(game->data.mlx);
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
