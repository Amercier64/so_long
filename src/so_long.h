/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amercier <amercier@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:24:02 by amercier          #+#    #+#             */
/*   Updated: 2026/01/10 16:49:20 by amercier         ###   ########.fr       */
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
# define IMGPATH_COIN "coin.xpm"
# define IMGPATH_PLAYER "redheart.xpm"
# define IMGPATH_WALL "wall.xpm"
# define IMGPATH_EXITLOCKED "hollow_circle.xpm"
# define IMGPATH_EXITUNLOCKED "full_circle.xpm"
# define IMG_COUNT 5

# define MAX_RES_WIDTH	1920
# define MAX_RES_HEIGHT 960
# define CELL_SIZE		32

typedef enum e_error
{
	SUCCESS = 0,
	ERR_MAP_INIT,
	ERR_MAP_SHAPE,
	ERR_ALLOC
}	t_error;

//structs
typedef struct	s_pos
{
	int	x;
	int y;
}	t_pos;

typedef struct	s_game_data
{
	bool	exit;
	int		coin;
	t_pos	player_pos;
}	t_game_data;

typedef struct	s_map
{
	int		width;
	int		height;
	char	**matrix;
}	t_map;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	void		*img[IMG_COUNT];
	t_map		map;
	t_game_data	game_data;
}	t_game;

//functions
int	exit_ok(void *param);
t_error map_init(t_game *game, int fd);
void	print_error(t_error errcode);
void	*error_map_init(t_list	*lst, void *ptr, t_error errcode);
t_error	game_init(t_game *game, int fd);

#endif
