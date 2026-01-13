/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:38:48 by amercier          #+#    #+#             */
/*   Updated: 2026/01/13 17:38:31 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	set_game_data(t_game *game, int x, int y);

t_error map_check(t_game *game)
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
	if (game->player.x == 0 || game->coin == 0 || game->exit == 0)
		return (ERR_MAP_UNCOMPLETE);
	return (SUCCESS);
}

static bool	set_game_data(t_game *game, int x, int y)
{
	char	c;

	c = game->map.matrix[y][x];
	if (c == 'P' && game->player.x == 0)
	{
		game->player.x = x;
		game->player.y = y;
	}
	else if (c == 'C')
		game->coin++;
	else if (c == 'E' && !game->exit)
		game->exit = 1;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}
