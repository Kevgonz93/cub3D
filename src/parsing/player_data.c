/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:22:21 by akwadran          #+#    #+#             */
/*   Updated: 2026/01/24 16:23:46 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static void	get_player_angle(t_game *game, char p)
{
	if (p == 'N')
		game->config.player_angle = 3 * PI / 2;
	else if (p == 'S')
		game->config.player_angle = PI / 2;
	else if (p == 'E')
		game->config.player_angle = 0;
	else if (p == 'W')
		game->config.player_angle = PI;
}

static void	set_player_parameters(t_game *game, int i, int j)
{
	game->player.x = (j + 0.5) * TILE_SIZE;
	game->player.y = (i + 0.5) * TILE_SIZE;
	game->config.map->grid[i][j] = '0';
	game->player.dir_x = cos(game->config.player_angle);
	game->player.dir_y = sin(game->config.player_angle);
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	game->config.fov = PI / 3;
}

int	get_player_data(t_game *game)
{
	t_map	*map;
	int		i;
	int		j;

	map = game->config.map;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S' ||
				map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
			{
				get_player_angle(game, map->grid[i][j]);
				set_player_parameters(game, i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (error("Player not found in grid"));
}
