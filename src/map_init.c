/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:17:28 by amercier          #+#    #+#             */
/*   Updated: 2026/01/08 14:30:52 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*get_rows(t_game *game, int fd);
static char	**get_matrix(t_game *game, t_list *rows);

t_error map_init(t_game *game, int fd)
{
	t_list	*rows;

	game->map.height = 0;	
	rows = get_rows(game, fd);
	if (!rows)
		return (ERR_MAP_INIT);
	game->map.matrix = get_matrix(game, rows);
	if (!game->map.matrix)
		return (ERR_MAP_INIT);
	return (check_map(game));
}

static t_error check_map(t_game)
{
	int		x;
	int		y;
	bool	check_flag;

	y = 0;
	check_flag = 1;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (!check_flag)
				return (ERR_MAP_INIT);
			if (check_flag && (y == 0 || y == map.height - 1))
				check_flag = (map.matrix[y][x] == '1');
			else if ()
			{
				check_flag = check_cell(map.matrix[y][x]);
			}
			x++;
		}
	}
}

static char	**get_matrix(t_game *game, t_list *rows)
{
	int		y;
	t_list	*tmp;

	y = 0;
	game->map.matrix = malloc(sizeof(char *) * map.height);
	if (!game->map.matrix)
		return error_map_init(rows, NULL, ERR_ALLOC);
	while (y < map.height)
	{
		game->map.matrix[y] = rows->content;
		tmp = rows->next;
		free(rows);
		rows = tmp;
		y++;
	}
}

static t_list	*get_rows(t_game *game, int fd)
{	
	t_list	*rows;
	t_list	*tmp;
	char	*row;

	rows = NULL;
	row = get_next_line(fd);
	while (row)
	{	
		if (game->map.height == 0)
			game->map.width = ft_strlen(row);
		if (ft_strlen(row) != game->map.width)
			return error_map_init(rows, row, ERR_MAP_SHAPE);
		tmp = ft_lstnew(row);
		if (!tmp)
			return error_map_init(rows, row, ERR_ALLOC);
		rows = ft_lstadd_back(&rows, tmp);
		game->map.height++;
		row = get_next_line(fd);
	}
	return (rows);
}
