/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:34:25 by kegonza           #+#    #+#             */
/*   Updated: 2026/02/04 17:35:15 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/src.h"

void	print_config(t_config *config)
{
	int	i;

	printf("NO: %s\n", config->no.path);
	printf("SO: %s\n", config->so.path);
	printf("WE: %s\n", config->we.path);
	printf("EA: %s\n", config->ea.path);
	printf("F: %X\n", config->floor_color);
	printf("C: %X\n", config->ceil_color);
	printf("GRID:\n");
	i = 0;
	while (config->map->grid[i])
	{
		printf("%sEOL\n", config->map->grid[i]);
		i++;
	}
}

void	print_player_data(t_game *game)
{
	printf("Player data: x %f, y %f, angle %f\n",
		game->player.x, game->player.y,
		game->config.player_angle);
}

void	print_array(char **array)
{
	int	i;

	if (!array)
		return ;
	printf("Printning array\n\n");
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
