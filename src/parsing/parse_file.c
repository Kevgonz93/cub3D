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
		//err
		free_array(buffer);
		return (1);
	}
	print_config(&game->config); // QUITAR
	free_array(buffer);
	return (0);
}
