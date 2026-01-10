/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:28 by kegonza           #+#    #+#             */
/*   Updated: 2025/12/21 00:30:43 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	free_img(t_game *game)
{
	if (game->img.img && game->mlx)
		mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = NULL;
	game->img.addr = NULL;
}

static void	free_map(t_map *map)
{
	if (map)
	{
		if (map->grid)
			free_array(map->grid);
	}
}

void	free_config(t_game *game)
{
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
		free_map(game->config.map);
		game->config.map = NULL;
	}
}

int	free_game(t_game *game, int ret)
{
	free_img(game);
	free_config(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	free(game->mlx); // revisarlo en Linux (posible doble free)
	game->mlx = NULL;
	return (ret);
}
