/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:28 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/24 15:03:17 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	free_img(t_game *game)
{
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = NULL;
		game->img.addr = NULL;
	}
}

static void	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		i = 0;
		if (map->grid)
		{
			while (i < map->height)
			{
				if (map->grid[i])
					free(map->grid[i]);
				i++;
			}
			free(map->grid);
		}
		free(map);
		map = NULL;
	}
}

void	free_config(t_game *game)
{
	if (game->config.no_tex)
		free(game->config.no_tex);
	if (game->config.so_tex)
		free(game->config.so_tex);
	if (game->config.we_tex)
		free(game->config.we_tex);
	if (game->config.ea_tex)
		free(game->config.ea_tex);
	if (game->config.map)
	{
		free_map(game->config.map);
		free(game->config.map);
	}
	game->config.no_tex = NULL;
	game->config.so_tex = NULL;
	game->config.we_tex = NULL;
	game->config.ea_tex = NULL;
	game->config.map = NULL;
}

// void	free_player(t_game *game)
// {
// 	(void)game;
// }

int	free_game(t_game *game, int ret)
{
	free_img(game);
	free_config(game);
	// free_player(game);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	game->mlx = NULL;
	return (ret);
}
