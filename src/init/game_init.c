/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:13:23 by amercier          #+#    #+#             */
/*   Updated: 2026/01/19 13:40:07 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_error	open_mapfile(char *filename, int *fd);
static t_error	win_init(t_game *game);
static t_error	load_imgs(t_game *game);

t_error	game_init(t_game *game, char *filename)
{
	int		fd;
	t_error	errcode;

	errcode = open_mapfile(filename, &fd);
	if (errcode)
		return (errcode);
	ft_memset(game, 0, sizeof(t_game));
	errcode = map_init(game, fd);
	if (!errcode)
		errcode = win_init(game);
	if (!errcode)
		errcode = load_imgs(game);
	if (errcode)
		free_game(game);
	close(fd);
	return (errcode);
}

static t_error	open_mapfile(char *filename, int *fd)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_memcmp(filename + len - 4, ".ber", 4))
		return (ERR_FILENAME);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (ERR_OPEN);
	return (SUCCESS);
}

static t_error	win_init(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = TILE_SIZE * game->map.width;
	win_height = TILE_SIZE * game->map.height;
	if (win_width > MAX_RES_WIDTH || win_height > MAX_RES_HEIGHT)
		return (ERR_WIN_SIZE);
	game->data.mlx = mlx_init();
	if (!game->data.mlx)
		return (ERR_ALLOC);
	game->data.win = mlx_new_window(game->data.mlx,
			win_width, win_height, WIN_TITLE);
	if (!game->data.win)
		return (ERR_ALLOC);
	return (SUCCESS);
}

static t_error	load_imgs(t_game *game)
{
	int			i;
	int			tile_width;
	int			tile_height;
	const char	*img_path[] = {IMGFILE_1, IMGFILE_C,
		IMGFILE_P, IMGFILE_ECLOSE, IMGFILE_EOPEN, IMGFILE_0};

	i = 0;
	while (i < IMG_COUNT)
	{
		game->data.img[i] = mlx_xpm_file_to_image(game->data.mlx,
				(char *)img_path[i], &tile_width, &tile_height);
		if (!game->data.img[i])
			return (ERR_IMG_LOAD);
		if (tile_width != TILE_SIZE || tile_height != TILE_SIZE)
			return (ERR_IMG_SIZE);
		i++;
	}
	return (SUCCESS);
}
