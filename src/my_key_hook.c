/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:27:34 by amercier          #+#    #+#             */
/*   Updated: 2026/01/17 18:43:57 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_key_hook(int keycode, void *param)
{
	t_game *game;

	game = param;
//	if (keycode == XK_Escape)
//		exit_ok(param);
	if (keycode == XK_w)
	{
//		mlx_put_image_to_window(game->data.mlx, game->data.win,
//				game->data.img[], game->player.x * TILE_SIZE,
//				game->player.y * TILE_SIZE);
		game->player.y += 1;
	}
	mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[2], game->player.x * TILE_SIZE,
			game->player.y * TILE_SIZE);
	return (0);
}
