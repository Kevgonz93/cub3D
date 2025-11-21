/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:13:18 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/21 21:56:36 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

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
}

int	main(int argc, char **argv)
{
	t_game	game;

	// 	1. Validar argumentos
	if (argc != 2)
		return (error("Usage: ./cub3D <map.cub>"));

	//   2. Inicializar estructura
	init_game(&game);

	//   3. Parsear archivo .cub
	if (parse_file(argv[1], &game) == -1)
		return (free_game(&game, 1));

	//	4. Inicializar MLX
	if (init_mlx(&game) != 0)
		return (1);

	//   5. Registrar hooks
	init_hooks(&game);

	//   6. Loop de MLX
	mlx_loop(game.mlx);
	return (free_game(&game, 0));
}
