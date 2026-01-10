/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:13:18 by kegonza           #+#    #+#             */
/*   Updated: 2026/01/10 20:46:08 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/src.h"

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

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		error("MLX can't be created");
		return (free_game(game, 1));
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
	{
		error("WIN can't be created");
		return (free_game(game, 1));
	}
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
	if (!game->img.addr)
	{
		error("IMG can't be created");
		return (free_game(game, 1));
	}
	return (0);
}

static void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	// render_frame(game);
	//mlx_loop_hook(game->mlx, render_frame, game);
	// mlx_loop_hook(game->mlx, render_2d_map, game); // QUITAR
}

static void	set_map(t_game *game)
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

void	test_main(t_game *game)
{
	if (is_cub("test.cub"))
		printf("is_cub works for tests!\n");
	// 1) Config “a mano”
	game->config.fov = 60.0 * PI / 180.0;   // radianes
	game->config.player_angle = 0.0;
	game->config.floor_color = 0x333333;
	game->config.ceil_color = 0x99AADD;
	game->config.no_tex = NULL;
	game->config.so_tex = NULL;
	game->config.we_tex = NULL;
	game->config.ea_tex = NULL;
	// 2) Mapa “a mano”
	set_map(game);
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

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	(void)argc;
	printf("validating arguments...\n");
	// 	1. Validar argumentos
	if (argc != 2)
		return (error("Usage: ./cub3D <map.cub>"));
	if (!is_cub(argv[1]))
		return (error("Map must have .cub format"));
	printf("initializing game...\n");
	//   2. Inicializar estructura
	init_game(&game);
	printf("parsing file...\n");
	//   3. Parsear archivo .cub
	if (parse_file(argv[1], &game))
		return (free_game(&game, 1));
	//test_main(&game);
	printf("initializing MLX...\n");
	//	4. Inicializar MLX
	if (init_mlx(&game) != 0)
		return (1);
	printf("registering hooks...\n");
	//   5. Registrar hooks
	init_hooks(&game);
	printf("starting MLX loop...\n");
	//   6. Loop de MLX
	mlx_loop(game.mlx);
	printf("exiting game...\n");
	//   7. Free and exit
	return (free_game(&game, 0));
}
