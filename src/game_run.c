/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:45:17 by amercier          #+#    #+#             */
/*   Updated: 2026/01/17 18:45:22 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void display_map(t_game *game);
static void *get_img(t_game *game, int x, int y);

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
		game->player.y -= 1;
	}
	mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->data.img[2], game->player.x * TILE_SIZE,
			game->player.y * TILE_SIZE);
	return (0);
}
void	game_run(t_game *game)
{
	display_map(game);
	mlx_key_hook(game->data.win, my_key_hook, game);
	mlx_loop(game->data.mlx);
}

static void display_map(t_game *game)
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
				continue;
			}
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static void *get_img(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game->map.matrix[y][x] == '1')
		img = game->data.img[0];
	else if (game->map.matrix[y][x] == 'C')
		img = game->data.img[1];
	else if (game->map.matrix[y][x] == 'P')
		img = game->data.img[2];
	else if (game->map.matrix[y][x] == 'E')
		img = game->data.img[3];
	return (img);
}
