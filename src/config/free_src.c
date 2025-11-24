/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:28 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/23 17:10:59 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/src.h"

void	free_img(t_game *game)
{
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = NULL;
		game->img.addr = NULL;
	}
}

void	free_config(t_game *game)
{
	int	i;

	if (game->config.no_tex)
	{
		free(game->config.no_tex);
		game->config.no_tex = NULL;
	}
	if (game->config.so_tex)
	{
		free(game->config.so_tex);
		game->config.so_tex = NULL;
	}
	if (game->config.we_tex)
	{
		free(game->config.we_tex);
		game->config.we_tex = NULL;
	}
	if (game->config.ea_tex)
	{
		free(game->config.ea_tex);
		game->config.ea_tex = NULL;
	}
	if (game->config.map)
	{
		i = 0;
		if (game->config.map->grid)
		{
			while (i < game->config.map->height)
			{
				if (game->config.map->grid[i])
					free(game->config.map->grid[i]);
				i++;
			}
			free(game->config.map->grid);
		}
		free(game->config.map);
		game->config.map = NULL;
	}
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
