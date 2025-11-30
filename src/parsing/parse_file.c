/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:07 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/30 21:48:57 by akwadran         ###   ########.fr       */
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

static int	validate_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' '))
		{
			printf("INCORRECT CHAR: %s\n", &line[i]); // QUITAR
			return (error("Map contains incorrect character"));
		}
		i++;
	}
	return (0);
}

static int	find_player(char *line)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (line[i])
	{
		if (line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W')
			player++;
		i++;
	}
	return (player);
}

static int	check_walls(char **lines, t_map *map)
{
	// por hacer
	(void)map;
	(void)lines;
	return (0);
}

static char	*rm_trailing_newline(char *line)
{
	char	*new;

	if (line[ft_strlen(line) - 1] == '\n')
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(new, line, ft_strlen(line));
	}
	else
		new = ft_strdup(line);
	return (new);
}

static int	get_grid(char **lines, int map_index, t_map *map)
{
	int	i;
	char	**grid;

	map->height = 0;
	i = map_index;
	while (lines[i])
	{
		map->height++;
		i++;
	}
	if (map->height == 0)
		return (error("Empty map"));
	grid = (char**)malloc(sizeof(char *) * map->height + 1);
	if (!grid)
		return (error("Grid: Malloc failed"));
	i = 0;
	while (lines[map_index])
	{
		grid[i] = rm_trailing_newline(lines[map_index]);
		i++;
		map_index++;
	}
	grid[i] = NULL;
	map->grid = grid;
	return (0);
}

static int	fill_empty_spaces(t_map *map)
{
	int	i;
	char	*tmp;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) < map->width)
		{
			tmp = (char *)malloc(sizeof(char) * (map->width + 1));
			ft_strlcpy(tmp, map->grid[i], ft_strlen(map->grid[i]));
			j = ft_strlen(map->grid[i]);
			while (j < map->width)
			{
				tmp[j] = ' ';
				j++;
			}
			tmp[j] = '\0';
			free(map->grid[i]);
			map->grid[i] = tmp;
		}
		i++;
	}
	return (0);
}

static int	parse_map(char **lines, t_game *game, int map_index)
{
	int	i;
	int	player;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (error("Map: Malloc failed"));
	map->width = 0;
	map->height = 0;
	i = map_index;
	player = 0;
	while (!strcmp(lines[i], "\n"))
		i++;
	map_index = i;
	if (get_grid(lines, map_index, map))
		return (1);
	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) > map->width)
			map->width = ft_strlen(map->grid[i]);
		if (validate_chars(map->grid[i]))
			return (1);
		player += find_player(map->grid[i]);
		i++;
	}
	if (player != 1)
		return (error("There must be exactly one player"));
	fill_empty_spaces(map);
	check_walls(map->grid, map);
	game->config.map = map;
	return (0);
}

int	parse_file(char *file, t_game *game)
{
	char	**lines;
	int		map_index;

	lines = get_lines(file);
	if (!lines)
		return (error("Buffer: Malloc failed"));
	print_array(lines); // QUITAR
	if (parse_textures(lines, game, &map_index))
	{
		free_array(lines);
		return (1);
	}
	if (parse_map(lines, game, map_index))
	{
		//err
		free_array(lines);
		return (1);
	}
	print_config(&game->config);
	free_array(lines);
	return (0);
}
