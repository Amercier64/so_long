/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:13:23 by amercier          #+#    #+#             */
/*   Updated: 2026/01/05 17:16:54 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	int fd = check_filename("")
	if (fd == -1)
		return (1);
	if (!map_init(game, fd))
		return (2);
	close(fd);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map->arr);
		return(3);
	}
	return (0);
}
