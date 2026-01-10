/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:50 by amercier          #+#    #+#             */
/*   Updated: 2026/01/10 17:37:00 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of args\n");
		return (1);
	}
	t_game game;
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		return (1);
	}
	t_error errcode = game_init(&game, fd);
	if (errcode != SUCCESS)
	{
		print_error(errcode);
		return (1);
	}
	int x;
	int y = 0;
	while (y < game.map.height)
	{
		x = 0;
		while (x < game.map.width)
		{
			ft_printf("%c", game.map.matrix[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("game coins : %d\n", game.game_data.coin);
	ft_printf("Player pos : x=%d y=%d\n", game.game_data.player_pos.x, game.game_data.player_pos.y);
	ft_printf("game exit : %d\n", game.game_data.exit);
}
