#include "../../includes/cub3d.h"
#include "../../includes/src.h"

static int	is_cub(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len <= 4)
		return (0);
	if (arg[len - 4] == '.' && arg[len - 3] == 'c' && arg[len - 2] == 'u'
		&& arg[len - 1] == 'b')
		return (1);
	return (0);
}

static void	test_set_map(t_game *game)
{
	static t_map	map;

	map.height = 6;
	map.width = 12;
	map.grid = (char **)malloc(sizeof(char *) * (map.height + 1));
	if (!map.grid)
		return ;
	map.grid[0] = ft_strdup("111111111111");
	map.grid[1] = ft_strdup("100000000001");
	map.grid[2] = ft_strdup("101010010101");
	map.grid[3] = ft_strdup("101010010101");
	map.grid[4] = ft_strdup("100000000001");
	map.grid[5] = ft_strdup("111111111111");
	map.grid[6] = NULL;
	game->config.map = &map;
}

void	test_config(t_game *game)
{
	if (is_cub("test.cub"))
		printf("is_cub works for tests!\n");
	// 1) Config “a mano”
	game->config.fov = 60.0 * PI / 180.0;   // radianes
	game->config.player_angle = 0.0;
	game->config.floor_color = 0x333333;
	game->config.ceil_color = 0x99AADD;
	game->config.no.path = NULL;
	game->config.so.path = NULL;
	game->config.we.path = NULL;
	game->config.ea.path = NULL;
	// 2) Mapa “a mano”
	test_set_map(game);
	// 3) Jugador “a mano” (en una celda '0')
	game->player.x = 2.5;
	game->player.y = 2.5;
	// Si tu código usa dir_x/dir_y en algún sitio, déjalos coherentes:
	game->player.dir_x = cos(game->config.player_angle);
	game->player.dir_y = sin(game->config.player_angle);
	// No hace falta plane_x/plane_y en tu enfoque actual
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
}