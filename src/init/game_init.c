/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:13:23 by amercier          #+#    #+#             */
/*   Updated: 2026/01/16 17:40:47 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_error open_mapfile(char *filename, int *fd);

t_error	game_init(t_game *game, char *filename)
{
	int fd;
	t_error errcode;

	errcode = open_mapfile(filename, &fd);
	if (errcode)
		return (errcode);
	ft_memset(game, 0, sizeof(t_game));
	errcode = map_init(game, fd);
	/*
	 * game->mlx = mlx_init();
	 * game->win = mlx_win(game->mlx);
	 * game->img = load_img(game);
	 */
	if (errcode)
		free_game(*game);
	return (errcode);
}

static t_error open_mapfile(char *filename, int *fd)
{
	size_t len;

	len = ft_strlen(filename);
	if (len < 5 || ft_memcmp(filename + len - 4, ".ber", 4))
		return (ERR_FILENAME);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (ERR_OPEN);
	return (SUCCESS);
}
