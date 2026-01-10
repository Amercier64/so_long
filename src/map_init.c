/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:17:28 by amercier          #+#    #+#             */
/*   Updated: 2026/01/10 17:58:55 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*get_rows(t_game *game, int fd);
static void get_matrix(t_game *game, t_list *rows);
static t_error check_map(t_game *game);
static bool	set_game_data(t_game *game, int x, int y);

t_error map_init(t_game *game, int fd)
{
	t_list	*rows;

	game->map.height = 0;
	rows = get_rows(game, fd);
	if (!rows)
		return (ERR_MAP_INIT);
	get_matrix(game, rows);
	if (!game->map.matrix)
		return (ERR_MAP_INIT);
	return (check_map(game));
}

static bool	set_game_data(t_game *game, int x, int y)
{
	char	c;

	c = game->map.matrix[y][x];
	if (c == 'P' && game->game_data.player_pos.x == 0)
	{
		game->game_data.player_pos.x = x;
		game->game_data.player_pos.y = y;
	}
	else if (c == 'C')
		game->game_data.coin++;
	else if (c == 'E' && !game->game_data.exit)
		game->game_data.exit = 1;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

static t_error check_map(t_game *game)
{
	int		x;
	int		y;
	bool	check_flag;

	y = 0;
	check_flag = 1;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (x * y == 0 || x == game->map.width - 1 ||
					y == game->map.height - 1)
				check_flag = (game->map.matrix[y][x] == '1');
			else
				check_flag = set_game_data(game, x, y);
			if (!check_flag)
				return (ERR_MAP_INIT);
			x++;
		}
		y++;
	}
	if (game->game_data.player_pos.x == 0 || game->game_data.coin == 0
			|| game->game_data.exit == 0)
		return (ERR_MAP_INIT);
	return (SUCCESS);
}

void	get_matrix(t_game *game, t_list *rows)
{
	int		y;
	t_list	*tmp;

	y = 0;
	game->map.matrix = malloc(sizeof(char *) * game->map.height);
	if (!game->map.matrix)
	{
		error_map_init(rows, NULL, ERR_ALLOC);
		return ;
	}
	while (y < game->map.height)
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
			game->map.width = ft_strlen(row) - 1;
		if (((int) ft_strlen(row) - 1) != game->map.width)
			return error_map_init(rows, row, ERR_MAP_SHAPE);
		tmp = ft_lstnew(row);
		if (!tmp)
			return error_map_init(rows, row, ERR_ALLOC);
		ft_lstadd_back(&rows, tmp);
		game->map.height++;
		row = get_next_line(fd);
	}
	return (rows);
}
