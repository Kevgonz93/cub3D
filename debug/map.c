/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:02:32 by akwadran          #+#    #+#             */
/*   Updated: 2026/02/04 17:55:55 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/src.h"

char	*make_full_line(int width, char c)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (width + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < width)
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*make_padding_line(char *old_line, int new_width)
{
	char	*new_line;
	int		i;

	if (!old_line || new_width < 2)
		return (NULL);
	new_line = make_full_line(new_width, '1');
	if (!new_line)
	{
		printf("Error allocating memory for padding line\n");
		return (NULL);
	}
	i = 0;
	while (old_line[i] && i < new_width - 2)
	{
		new_line[i + 1] = old_line[i];
		i++;
	}
	return (new_line);
}

void	print_error(char *message, char **new_grind)
{
	printf("Error: %s\n", message);
	if (new_grind)
		free_array(new_grind);
}

void	paddeding_map(t_game *game)
{
	int		old_height;
	int		new_width;
	int		new_height;
	char	**new_grid;
	int		i;

	old_height = game->config.map->height;
	new_width = game->config.map->width + 2;
	new_height = old_height + 2;
	new_grid = NULL;
	new_grid = (char **)malloc(sizeof(char *) * (new_height + 1));
	if (!new_grid)
		return ;
	new_grid[0] = make_full_line(new_width, '1');
	if (!new_grid[0])
		print_error("Error allocating memory for map padding", new_grid);
	i = 0;
	while (++i <= old_height)
	{
		new_grid[i] = make_padding_line(game->config.map->grid[i - 1],
				new_width);
		if (!new_grid[i])
			print_error("Error allocating memory for map padding", new_grid);
	}
	new_grid[new_height - 1] = make_full_line(new_width, '1');
	if (!new_grid[new_height - 1])
		print_error("Error allocating memory for map padding", new_grid);
	new_grid[new_height] = NULL;
	free_array(game->config.map->grid);
	game->config.map->grid = new_grid;
	game->config.map->width = new_width;
	game->config.map->height = new_height;
}
