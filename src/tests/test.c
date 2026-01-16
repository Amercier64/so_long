#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void	*ft_memset(void *s, int c, size_t n);

typedef struct	s_pos
{
	int	x;
	int y;
}	t_pos;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img[5];
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
	t_pos	player;
	t_map	map;
	t_data	data;
}	t_game;

int main()
{
	t_game	*game;
	t_map	*map;

	game = malloc(sizeof(t_game));
	(void) map;
	printf("game: %p\n", game);
	printf("game.map: %p\n", &(game->map));
	map = &game->map;
	printf("map: %p\n", map);
}
