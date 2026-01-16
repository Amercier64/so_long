/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:17:28 by amercier          #+#    #+#             */
/*   Updated: 2026/01/16 16:39:32 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_error get_rows(t_map *map, int fd, t_list **rows);
static t_error	get_matrix(t_map *map, t_list *rows);

t_error map_init(t_game *game, int fd)
{
	t_list	*rows;
	t_error	errcode;

	errcode = get_rows(&game->map, fd, &rows);
	if (!errcode)
		errcode = get_matrix(&game->map, rows);
	if (!errcode)
		errcode = map_check(game);
	if (!errcode)
		errcode = lab_check(game);
	if (errcode)
		free_map(&game->map);
	return (errcode);
}

static t_error get_rows(t_map *map, int fd, t_list **rows)
{
	t_list	*tmp;
	char	*row;

	*rows = NULL;
	row = get_next_line(fd);
	while (row)
	{
		if (map->height == 0)
			map->width = ft_strlen(row) - 1;
		if (((int) ft_strlen(row) - 1) != map->width)
		{
			free_rows(rows, row);
			return (ERR_MAP_SHAPE);
		}
		tmp = ft_lstnew(row);
		if (!tmp)
		{
			free_rows(rows, row);
			return (ERR_ALLOC);
		}
		ft_lstadd_back(rows, tmp);
		map->height++;
		row = get_next_line(fd);
	}
	return (SUCCESS);
}

static t_error	get_matrix(t_map *map, t_list *rows)
{
	int		y;
	t_list	*tmp;

	y = 0;
	map->matrix = malloc(sizeof(char *) * map->height);
	if (!map->matrix)
	{
		free_rows(&rows, NULL);
		return (ERR_ALLOC);
	}
	while (y < map->height)
	{
		map->matrix[y] = rows->content;
		tmp = rows->next;
		free(rows);
		rows = tmp;
		y++;
	}
	return (SUCCESS);
}
