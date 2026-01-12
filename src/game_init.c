/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:13:23 by amercier          #+#    #+#             */
/*   Updated: 2026/01/12 09:29:52 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	game_init(t_game *game, int fd)
{
	game->coin = 0;
	game->player_pos.x = 0;
	game->exit = 0;

	/*
	 * game->mlx = mlx_init();
	 * game->win = mlx_win(game->mlx);
	 * game->img = load_img(game);
	 */
	return (map_init(game, fd));
}
