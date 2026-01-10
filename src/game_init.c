/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:13:23 by amercier          #+#    #+#             */
/*   Updated: 2026/01/10 17:20:46 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	game_init(t_game *game, int fd)
{
	game->game_data.coin = 0;
	game->game_data.player_pos.x = 0;
	game->game_data.exit = 0;

	/*
	 * game->mlx = mlx_init();
	 * game->win = mlx_win(game->mlx);
	 * game->img = load_img(game);
	 */
	return (map_init(game, fd));
}
