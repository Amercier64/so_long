/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:00:48 by amercier          #+#    #+#             */
/*   Updated: 2026/01/19 13:19:12 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_error	copy_map(t_map map, t_map *copy);
static void		floodfill(t_map map, char **iscolored, int x, int y);
static int		reachable_count(t_map lab, char **map);

t_error	lab_check(t_game *game)
{
	t_map	lab;
	t_error	errcode;

	errcode = copy_map(game->map, &lab);
	if (errcode)
		return (errcode);
	floodfill(game->map, lab.matrix, game->player.x, game->player.y);
	if (reachable_count(lab, game->map.matrix) != game->coin + 1)
		errcode = ERR_MAP_LAB;
	free_map(&lab);
	return (errcode);
}

static int	reachable_count(t_map lab, char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < lab.height)
	{
		x = 0;
		while (x < lab.width)
		{
			if ((map[y][x] == 'C' || map[y][x] == 'E')
					&& lab.matrix[y][x])
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	floodfill(t_map map, char **iscolored, int x, int y)
{
	if (iscolored[y][x] || map.matrix[y][x] == '1')
		return ;
	iscolored[y][x] = map.matrix[y][x];
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
			free_map(copy);
			return (ERR_ALLOC);
		}
		ft_memset(copy->matrix[y], 0, sizeof(char) * copy->width);
		y++;
	}
	return (SUCCESS);
}
