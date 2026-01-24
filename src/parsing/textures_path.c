/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:33 by akwadran          #+#    #+#             */
/*   Updated: 2026/01/24 16:32:26 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

int	get_path(t_tex *tex, char *line, int i, bool *check)
{
	if (tex->path)
	{
		*check = false;
		return (error("There must be exactly one texture for each wall side"));
	}
	tex->path = ft_substr(line, i, ft_strlen(&line[i]) - 1);
	if (!tex->path)
	{
		*check = false;
		return (error("Can´t get texture path"));
	}
	return (0);
}

int	get_tex(char *line, t_game *game)
{
	int		i;
	bool	check;

	if (!line || !game)
		return (1);
	i = 2;
	check = true;
	while (ft_isspace(line[i]))
		i++;
	if (!strncmp(line, "NO", 2))
		get_path(&game->config.no, line, i, &check);
	else if (!strncmp(line, "SO", 2))
		get_path(&game->config.so, line, i, &check);
	else if (!strncmp(line, "WE", 2))
		get_path(&game->config.we, line, i, &check);
	else if (!strncmp(line, "EA", 2))
		get_path(&game->config.ea, line, i, &check);
	if (!check)
		return (1);
	return (0);
}
