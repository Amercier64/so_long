/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:00:48 by amercier          #+#    #+#             */
/*   Updated: 2026/01/13 17:50:39 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_error	copy_mat(t_map *copy);

t_error	lab_check(t_game *game)
{
	t_map	iscolored;
	t_error errcode;

	errcode = copy_map(game->map, &iscolored);
	if (!errcode)
	{
		floodfill(game->map, iscolored.matrix, game.player.x, game.player.y);
		free_map(iscolored);
	}
	return (errcode);
}

void	floodfill(t_map map, char **iscolored, int x, int y)
{
	if (x * y == 0 || x == map.width || y == map.height)
		return;
	if (!iscolored[y][x] && map.matrix[y][x] != '1')
		iscolored[y][x] = '1';
	floodfill(map, iscolored, x, y - 1);
	floodfill(map, iscolored, x, y + 1);
	floodfill(map, iscolored, x - 1, y);
	floodfill(map, iscolored, x + 1, y);
}

/*
 *	Copy the map and set every characters to (white) '0'
 */
static t_error	copy_map(t_map map, t_map *copy)
{
	int		y;

	copy->height = map.height;
	copy->width = map.width;
	copy->matrix = malloc(sizeof(char *) * copy->height);
	if (!copy->matrix)
		return (ERR_ALLOC);
	ft_memset(copy->matrix, 0, sizeof(char *) * copy->height);
	y = 0;
	while (y < copy->height)
	{
		copy->matrix[y] = malloc(sizeof(char) * copy->width);
		if (!copy->matrix[y])
		{
			free_map(*copy);
			return (ERR_ALLOC);
		}
		ft_memset(copy->matrix[y], 0, sizeof(char) * copy->width);
		y++;
	}
	return (SUCCESS);
}
