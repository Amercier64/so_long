/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:24:02 by amercier          #+#    #+#             */
/*   Updated: 2026/01/18 19:07:58 by amercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//libs
# include "mlx.h"
# include "mlx_int.h"
# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>

//consts
# define IMG_DIR "textures/"
# define IMGFILE_1		IMG_DIR "wall.xpm"
# define IMGFILE_C		IMG_DIR "coin.xpm"
# define IMGFILE_P		IMG_DIR "redheart.xpm"
# define IMGFILE_ECLOSE	IMG_DIR "full_circle.xpm"
# define IMGFILE_EOPEN	IMG_DIR "hollow_circle.xpm"
# define IMGFILE_0		IMG_DIR "background.xpm"
# define IMG_FILENAMES {IMGFILE_1, IMGFILE_C, \
		IMGFILE_P, IMGFILE_ECLOSE, IMGFILE_EOPEN, IMGFILE_0}
# define IMG_COUNT 6

# define WIN_TITLE "so_long"
# define MAX_RES_WIDTH	1920
# define MAX_RES_HEIGHT 960
# define TILE_SIZE		32

typedef enum e_error
{
	SUCCESS = 0,
	ERR_ARGS,
	ERR_FILENAME,
	ERR_OPEN,
	ERR_ALLOC,
	ERR_MAP_SHAPE,
	ERR_MAP_UNCOMPLETE,
	ERR_MAP_INIT,
	ERR_MAP_LAB,
	ERR_WIN_SIZE,
	ERR_IMG_LOAD,
	ERR_IMG_SIZE
}	t_error;

//structs
typedef struct	s_pos
{
	int	x;
	int y;
}	t_pos;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img[IMG_COUNT];
}	t_data;

typedef struct	s_map
{
	int		width;
	int		height;
	char	**matrix;
}	t_map;

typedef struct	s_game
{
	bool	exit;
	int		coin;
	int		move;
	t_pos	player;
	t_map	map;
	t_data	data;
}	t_game;

//functions
t_error	game_init(t_game *game, char *filename);
t_error map_init(t_game *game, int fd);
t_error map_check(t_game *game);
t_error	lab_check(t_game *game);
void	game_run(t_game *game);
int		my_key_hook(int keycode, void *param);
void	free_rows(t_list **rows, char *row);
void	free_game(t_game *game);
void	free_map(t_map *map);
void	print_error(t_error errcode);

#endif
