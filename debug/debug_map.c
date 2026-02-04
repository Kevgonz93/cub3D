/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:34:19 by kegonza           #+#    #+#             */
/*   Updated: 2026/02/04 17:41:49 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/src.h"

int	draw_tile(t_game *game, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE)
	{
		j = 0;
		while (j < TILE)
		{
			my_mlx_pixel_put(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_player(t_game *game, double x, double y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			my_mlx_pixel_put(&game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

void	render_mini_map(char c, t_game *game, int x, int aux_y)
{
	t_map	*map;

	map = game->config.map;
	if (c == '1')
		draw_tile(game, x * TILE, aux_y, (0 << 16 | 0 << 8 | 205));
	else if (c == '0' || c == 'S' || c == 'N' || c == 'E' || c == 'W')
	{
		draw_tile(game, x * TILE, aux_y, (250 << 16 | 235 << 8 | 215));
		draw_player(game, game->player.x * TILE,
			HEIGHT - (map->height * TILE) + (game->player.y * TILE),
			(128 << 16 | 0 << 8 | 0));
	}
}

int	render_2d_map(t_game *game)
{
	int			x;
	int			y;
	t_map		*map;
	int			aux_y;

	map = game->config.map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			aux_y = HEIGHT - (map->height * TILE) + (y * TILE);
			render_mini_map(map->grid[y][x], game, x, aux_y);
			x++;
		}
		y++;
	}
	return (0);
}
