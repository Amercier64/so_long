/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 23:00:40 by amercier          #+#    #+#             */
/*   Updated: 2026/01/14 13:02:09 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//char **map_init(int fd)
//{
//	**
//}

int	X = 0;

//init parse map -> check validity ->  mlx_putimgtowin for each square of map
//move -> checks move -> modify map -> loop imgtowin

int	my_key_hook(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	if (keycode == XK_Escape)
		exit_ok(param);
	if (keycode == XK_BackSpace)
	{
		X += 32;
		mlx_clear_window(game->data.mlx, game->data.win);
		mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img[0], X, 400-32);
	}
	return (0);
}

int main(void)
{
	t_game	game;
	int		x = 1920;
	int		y = 960;
	char	*title = "Test_window";
	int		cell_size;
//	void	*img;


	game.data.mlx = mlx_init();
	game.data.win = mlx_new_window(game.data.mlx, x, y, title);
	game.data.img[0] = mlx_xpm_file_to_image(game.data.mlx, "textures/coin.xpm", &cell_size, &cell_size);
	if (!game.data.img[0])
	{
		perror("Error\n");
		return 1;
	}
	mlx_put_image_to_window(game.data.mlx, game.data.win, game.data.img[0], X, y - CELL_SIZE);
	mlx_hook(game.data.win, DestroyNotify, NoEventMask, exit_ok, &game);
//	mlx_hook(game.win, KeyPress, KeyPressMask, my_key_hook, &game);

	mlx_key_hook(game.data.win, my_key_hook, &game);
	mlx_loop(game.data.mlx);
}
