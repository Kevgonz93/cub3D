/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:52:28 by kegonza           #+#    #+#             */
/*   Updated: 2026/01/24 16:52:16 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static void	free_tex(t_game *game, t_tex *tex)
{
	if (tex->img && game->mlx)
		mlx_destroy_image(game->mlx, tex->img);
	tex->img = NULL;
	tex->addr = NULL;
	if (tex->path)
		free(tex->path);
	tex->path = NULL;
}

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
		free(map);
	}
}

void	free_config(t_game *game)
{
	free_tex(game, &game->config.no);
	free_tex(game, &game->config.so);
	free_tex(game, &game->config.we);
	free_tex(game, &game->config.ea);
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
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	return (ret);
}
