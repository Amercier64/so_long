/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:45:17 by amercier          #+#    #+#             */
/*   Updated: 2026/03/03 17:26:58 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_prog(void *param);
static void	display_map(t_game *game);
static void	*get_img(t_game *game, int x, int y);

void	game_run(t_game *game)
{
	t_pos	prev_pos;

	prev_pos = game->player;
	display_map(game);
	mlx_key_hook(game->data.win, my_key_hook, game);
	mlx_hook(game->data.win, DestroyNotify, NoEventMask, exit_prog, game);
	mlx_loop(game->data.mlx);
}

static int	exit_prog(void *param)
{
	t_game	*game;

	game = param;
	mlx_loop_end(game->data.mlx);
	return (0);
}

static void	display_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			img = get_img(game, x, y);
			if (img == NULL)
			{
				x++;
				continue ;
			}
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static void	*get_img(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game->map.matrix[y][x] == '1')
		img = game->data.img[WALL];
	else if (game->map.matrix[y][x] == 'C')
		img = game->data.img[COIN];
	else if (game->map.matrix[y][x] == 'P')
		img = game->data.img[PLAYER];
	else if (game->map.matrix[y][x] == 'E')
		img = game->data.img[ECLOSE];
	else if (game->map.matrix[y][x] == '0')
		img = game->data.img[EMPTY];
	return (img);
}
