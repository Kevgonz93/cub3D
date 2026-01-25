/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:07 by kegonza           #+#    #+#             */
/*   Updated: 2026/01/25 21:45:37 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && i < ((int)ft_strlen(line) - 1))
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
				|| line[i] == ' '))
		{
			printf("wrong char ||%c||\n", line[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

static bool	all_textures_found(t_game *game)
{
	if (game->config.no.path && game->config.so.path && game->config.we.path
		&& game->config.ea.path && game->config.floor_color_found
		&& game->config.ceil_color_found)
		return (1);
	return (0);
}

int	find_map(char **lines, int i, int *map_index)
{
	i--;
	while (lines[++i])
	{
		if (!strcmp(lines[i], "\n"))
			continue ;
		else if (is_map_line(lines[i]))
			break ;
		else
			return (error("Unexpected line: file must contain "
					"4 textures, 2 colors and a map"));
	}
	*map_index = i;
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
		{
			if (get_tex(lines[i], game))
				return (1);
		}
		else if (!strncmp(lines[i], "F", 1) || !strncmp(lines[i], "C", 1))
		{
			if (get_color(lines[i], game))
				return (1);
		}
		else
			return (error("Unexpected line: file must contain "
					"4 textures, 2 colors and a map"));
	}
	if (find_map(lines, i, map_index))
		return (1);
	return (0);
}

int	parse_file(char *file, t_game *game)
{
	char	**buffer;
	int		map_index;

	buffer = get_buffer(file);
	if (!buffer)
		return (1);
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
	free_array(buffer);
	if (get_player_data(game))
		return (1);
	return (0);
}
