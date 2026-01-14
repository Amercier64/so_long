/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:50 by amercier          #+#    #+#             */
/*   Updated: 2026/01/14 15:48:03 by amercier         ###   ########.fr       */
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
	if (errcode)
	{
		print_error(errcode);
		return (1);
	}
	else
		ft_printf("SUCCESS !\n");
	free_game(game);
}
