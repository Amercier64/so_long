/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:27:34 by amercier          #+#    #+#             */
/*   Updated: 2026/01/21 15:33:55 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update(t_game *game, t_pos prev_pos);
static int	get_pos(t_game *game, char dim, char object);
static void	move_player(t_game *game, t_pos prev_pos);
static int	move_allowed(t_game *game);

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

static void	update(t_game *game, t_pos prev_pos)
{
	if (move_allowed(game))
		move_player(game, prev_pos);
	else
		game->player = prev_pos;
	if (game->coin == 0)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[4], get_pos(game, 'x', 'E') * TILE_SIZE,
			get_pos(game, 'y', 'E') * TILE_SIZE);
}

static void	move_player(t_game *game, t_pos prev_pos)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.matrix[prev_pos.y][prev_pos.x] == 'E')
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[3], prev_pos.x * TILE_SIZE,
			prev_pos.y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[5], prev_pos.x * TILE_SIZE,
			prev_pos.y * TILE_SIZE);
	mlx_put_image_to_window(game->data.mlx, game->data.win,
		game->data.img[2], game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);
	game->move++;
	ft_printf("Movements: %d\n", game->move);
	if (game->map.matrix[y][x] == 'C')
		game->coin--;
	else if (game->map.matrix[y][x] == 'E' && game->coin == 0)
	{
		ft_printf("YOU WON !\n");
		mlx_loop_end(game->data.mlx);
	}
}

static int	move_allowed(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.matrix[y][x] == '1')
		return (0);
	return (1);
}

static int	get_pos(t_game *game, char dim, char object)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.matrix[y][x] == object && dim == 'x')
				return (x);
			else if (game->map.matrix[y][x] == object && dim == 'y')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}
