/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:07 by kegonza           #+#    #+#             */
/*   Updated: 2025/12/08 16:36:37 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static bool	all_textures_found(t_game *game)
{
	if (game->config.no_tex && game->config.so_tex && game->config.we_tex
		&& game->config.ea_tex && game->config.floor_color > 0
		&& game->config.ceil_color > 0)
		return (1);
	return (0);
}

static int	parse_textures(char **lines, t_game *game, int *map_index)
{
	int	i;

	i = -1;
	while (lines[++i] && !all_textures_found(game))
	{
		if (!strcmp(lines[i], "\n"))
			continue ;
		else if (!strncmp(lines[i], "NO", 2) || !strncmp(lines[i], "SO", 2)
			|| !strncmp(lines[i], "WE", 2) || !strncmp(lines[i], "EA", 2))
			get_tex(lines[i], game);
		else if (!strncmp(lines[i], "F", 1) || !strncmp(lines[i], "C", 1))
			get_color(lines[i], game);
		else
			return (error("Unexpected line"));
	}
	*map_index = i;
	return (0);
}

static void	get_player_angle(t_game *game, char p)
{
	if (p == 'N')
		game->config.player_angle = 0;
	else if (p == 'S')
		game->config.player_angle = PI;
	else if (p == 'E')
		game->config.player_angle = PI / 2;
	else if (p == 'W')
		game->config.player_angle = 3 * PI / 2;
}

static int	get_player_data(t_game *game)
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
				game->player.x = j;
				game->player.y = i;
				get_player_angle(game, map->grid[i][j]);
				game->player.dir_x = cos(game->config.player_angle);
				game->player.dir_y = sin(game->config.player_angle);
				game->player.plane_x = 0.0;
				game->player.plane_y = 0.0;
				game->config.fov = PI / 3;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (error("Player not found in grid"));
}

int	parse_file(char *file, t_game *game)
{
	char	**buffer;
	int		map_index;

	buffer = get_buffer(file);
	if (!buffer)
		return (error("Buffer: Malloc failed"));
	if (parse_textures(buffer, game, &map_index))
	{
		free_array(buffer);
		return (1);
	}
	if (parse_map(buffer, game, map_index))
	{
		free_array(buffer);
		return (1);
	}
	print_config(&game->config); // QUITAR
	free_array(buffer);
	if (get_player_data(game))
		return (1);
	print_player_data(game); // QUITAR
	return (0);
}
