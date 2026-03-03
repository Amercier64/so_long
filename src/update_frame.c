/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:11:43 by amercier          #+#    #+#             */
/*   Updated: 2026/03/03 17:29:25 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_pos(t_game *game, char dim, char object);
static void	move_player(t_game *game, t_pos prev_pos);
static int	move_allowed(t_game *game);
static void	update_coins(t_game *game);

void	update(t_game *game, t_pos prev_pos)
{
	if (move_allowed(game))
		move_player(game, prev_pos);
	else
		game->player = prev_pos;
	if (game->coin == 0)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[EOPEN], get_pos(game, 'x', 'E') * TILE_SIZE,
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
			game->data.img[ECLOSE], prev_pos.x * TILE_SIZE,
			prev_pos.y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[EMPTY], prev_pos.x * TILE_SIZE,
			prev_pos.y * TILE_SIZE);
	mlx_put_image_to_window(game->data.mlx, game->data.win,
		game->data.img[PLAYER], game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);
	game->move++;
	ft_printf("Movements: %d\n", game->move);
	if (game->map.matrix[y][x] == 'C')
		update_coins(game);
	else if (game->map.matrix[y][x] == 'E' && game->coin == 0)
	{
		ft_printf("YOU WON !\n");
		mlx_loop_end(game->data.mlx);
	}
}

static void	update_coins(t_game *game)
{
	game->map.matrix[game->player.y][game->player.x] = 0;
	game->coin--;
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
