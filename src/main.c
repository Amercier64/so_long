/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:02:50 by amercier          #+#    #+#             */
/*   Updated: 2026/01/16 16:27:47 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;
	t_error	errcode;

	if (argc != 2)
		errcode = ERR_ARGS;
	else
		errcode = game_init(&game, argv[1]);
	if (errcode)
		print_error(errcode);
	else
	{
		ft_printf("SUCCESS !\n");
		free_game(game);
	}
	return (errcode);
}
