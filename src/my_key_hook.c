/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:27:34 by amercier          #+#    #+#             */
/*   Updated: 2026/03/03 17:29:43 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_key_hook(int keycode, void *param)
{
	t_game	*game;
	t_pos	prev_pos;

	game = param;
	prev_pos = game->player;
	if (keycode == XK_Escape)
	{
		mlx_loop_end(game->data.mlx);
		return (0);
	}
	else if (keycode == XK_w)
		game->player.y -= 1;
	else if (keycode == XK_s)
		game->player.y += 1;
	else if (keycode == XK_a)
		game->player.x -= 1;
	else if (keycode == XK_d)
		game->player.x += 1;
	else
		return (0);
	update(game, prev_pos);
	return (0);
}
