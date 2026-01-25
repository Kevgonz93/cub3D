/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:13:18 by kegonza           #+#    #+#             */
/*   Updated: 2026/01/25 21:50:08 by akwadran         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_game	game;

	printf("validating arguments...\n");
	if (argc != 2)
		return (error("Usage: ./cub3D <map.cub>"));
	if (!is_cub(argv[1]))
		return (error("Map must have .cub format"));
	printf("initializing game...\n");
	init_game(&game);
	printf("parsing file...\n");
	if (parse_file(argv[1], &game))
		return (free_game(&game, 1));
	printf("initializing MLX...\n");
	if (init_mlx(&game) != 0)
		return (1);
	printf("loading textures...\n");
	if (init_textures(&game))
		return (free_game(&game, 1));
	printf("registering hooks...\n");
	init_hooks(&game);
	printf("starting MLX loop...\n");
	mlx_loop(game.mlx);
	printf("exiting game...\n");
	return (free_game(&game, 0));
}
