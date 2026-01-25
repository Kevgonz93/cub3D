/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_empty_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:35:55 by akwadran          #+#    #+#             */
/*   Updated: 2026/01/25 20:49:33 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static bool	is_other_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != 'S'
			&& line[i] != 'N' && line[i] != 'E' && line[i] != 'W')
			return (1);
		i++;
	}
	return (0);
}

static bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] != ' ' && line[i] != '1' && line[i] != '0'
				&& line[i] != 'S' && line[i] != 'N' && line[i] != 'E'
				&& line[i] != 'W'))
			return (1);
		i++;
	}
	return (0);
}

int	check_for_empty_lines(char **grid)
{
	int		i;
	bool	empty;

	i = 0;
	empty = false;
	while (grid && grid[i])
	{
		if (is_empty_line(grid[i]))
			empty = 1;
		else if (is_other_line(grid[i]))
			return (error("Map must be the last element"), 1);
		else if (is_map_line(grid[i]) && empty)
			return (error("Map can´t contain an empty line"), 1);
		i++;
	}
	return (0);
}
