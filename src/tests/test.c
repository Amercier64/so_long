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
	t_game	game;
	t_pos	pos;

	game.player.x = 10;
	game.player.y = 20;
	pos = game.player;
	printf("x = %d y = %d\n", game.player.x, game.player.y);
	printf("x = %d y = %d\n", pos.x, pos.y);
	printf("gp = %p\npos = %p", &game.player, &pos);
	game.player.x = 33;
	game.player.y = 77;
	printf("x = %d y = %d\n", game.player.x, game.player.y);
	printf("x = %d y = %d\n", pos.x, pos.y);
	pos.x = 42;
	pos.y = 68;
	printf("x = %d y = %d\n", game.player.x, game.player.y);
	printf("x = %d y = %d\n", pos.x, pos.y);
}
