/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:02:13 by akwadran          #+#    #+#             */
/*   Updated: 2026/01/25 21:45:09 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static bool	valid_range(int color[3])
{
	if (color[0] >= 0 && color[0] <= 255 && color[1] >= 0 && color[1] <= 255
		&& color[2] >= 0 && color[2] <= 255)
		return (1);
	return (0);
}

static bool	valid_chars(char *line, int color_index)
{
	while (line[color_index])
	{
		if (!(ft_isdigit(line[color_index]) || line[color_index] == ','
				|| ft_isspace(line[color_index])))
			return (0);
		color_index++;
	}
	return (1);
}

static int	convert_color(char *line, int color_index, unsigned int *trgb)
{
	char	**color;
	int		i;
	int		rgb[3];

	color = ft_split(&line[color_index], ',');
	if (!color)
		return (error("Color: Malloc failed"));
	i = 0;
	while (color[i])
		i++;
	if (i > 3)
		return (error("Incorrect color format: must be R,G,B range [0,255]"));
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	free_array(color);
	if (!valid_range(rgb))
		return (error("Incorrect color format: must be R,G,B range [0,255]"));
	*trgb = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	return (0);
}

static int	assign_color(t_game *game, char *line, unsigned int trgb)
{
	if (!strncmp(line, "F", 1))
	{
		if (!game->config.floor_color_found)
		{
			game->config.floor_color = trgb;
			game->config.floor_color_found = true;
		}
		else
			return (error("There must be only one floor color"));
	}
	else
	{
		if (!game->config.ceil_color_found)
		{
			game->config.ceil_color = trgb;
			game->config.ceil_color_found = true;
		}
		else
			return (error("There must be only one ceiling color"));
	}
	return (0);
}

int	get_color(char *line, t_game *game)
{
	int				i;
	int				color_index;
	unsigned int	trgb;

	if (!line || !game)
		return (1);
	i = 1;
	while (ft_isspace(line[i]))
		i++;
	color_index = i;
	if (!valid_chars(line, color_index))
		return (error("Incorrect color format"));
	if (convert_color(line, color_index, &trgb))
		return (1);
	if (assign_color(game, line, trgb))
		return (1);
	return (0);
}
