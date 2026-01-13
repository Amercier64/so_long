/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:17:28 by amercier          #+#    #+#             */
/*   Updated: 2026/01/13 17:15:48 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_error get_rows(t_game *game, int fd, t_list **rows);
static t_error get_matrix(t_game *game, t_list *rows);

t_error map_init(t_game *game, int fd)
{
	t_list	*rows;
	t_error	errcode;

	game->map.height = 0;
	errcode = get_rows(game, fd, &rows);
	if (!errcode)
		errcode = get_matrix(game, rows);
	if (!errcode)
	{
		errcode = map_check(game);
		if (errcode)
			free_map(game->map);
	}
	return (errcode);
}

static t_error get_rows(t_game *game, int fd, t_list **rows)
{
	t_list	*tmp;
	char	*row;

	*rows = NULL;
	row = get_next_line(fd);
	while (row)
	{
		if (game->map.height == 0)
			game->map.width = ft_strlen(row) - 1;
		if (((int) ft_strlen(row) - 1) != game->map.width)
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
		game->map.height++;
		row = get_next_line(fd);
	}
	return (SUCCESS);
}

static t_error	get_matrix(t_game *game, t_list *rows)
{
	int		y;
	t_list	*tmp;

	y = 0;
	game->map.matrix = malloc(sizeof(char *) * game->map.height);
	if (!game->map.matrix)
	{
		free_rows(&rows, NULL);
		return (ERR_ALLOC);
	}
	while (y < game->map.height)
	{
		game->map.matrix[y] = rows->content;
		tmp = rows->next;
		free(rows);
		rows = tmp;
		y++;
	}
	return (SUCCESS);
}
