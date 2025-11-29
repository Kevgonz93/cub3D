/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:42:07 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/29 02:45:59 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static bool	all_textures_found(t_game *game)
{
	if (game->config.no_tex && game->config.so_tex && game->config.we_tex
		&& game->config.ea_tex && game->config.floor_color
		&& game->config.ceil_color)
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
		{
			// err: unexpected line
			return (1);
		}
	}
	*map_index = i;
	return (0);
}

static int	parse_map()
{
	return (0);
}

int	parse_file(char *file, t_game *game)
{
	char	**lines;
	int		map_index;

	(void)game;

	lines = get_lines(file);
	if (!lines)
		return (error("Malloc failed"));
	if (parse_textures(lines, game, &map_index))
	{
		//err
		free_array(lines);
		return (1);
	}
	if (parse_map())
	{
		//err
		free_array(lines);
		return (1);
	}

    

    /*
	game->config.no_tex;
    game->config.so_tex;
    game->config.we_tex;
    game->config.ea_tex;
    game->config.floor_color;
    game->config.ceil_color;
    game->config.map;
    */
	printf("error?\n");
	free_array(lines);
	return (0);
}
