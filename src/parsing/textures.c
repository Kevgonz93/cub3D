#include "../../includes/src.h"

int	get_tex(char *line, t_game *game)
{
	int	i;

	if (!line || !game)
		return (1);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (!strncmp(line, "NO", 2))
		game->config.no_tex = ft_substr(line, i, ft_strlen(&line[i]));
	else if (!strncmp(line, "SO", 2))
		game->config.so_tex = ft_substr(line, i, ft_strlen(&line[i]));
	else if (!strncmp(line, "WE", 2))
		game->config.we_tex = ft_substr(line, i, ft_strlen(&line[i]));
	else if (!strncmp(line, "EA", 2))
		game->config.ea_tex = ft_substr(line, i, ft_strlen(&line[i]));
	return (0);
}

static bool	valid_range(int color[3])
{
	if (color[0] >= 0 && color[0] <= 255 && color[1] >= 0 && color[1] <= 255
		&& color[2] >= 0 && color[2] <= 255)
		return (1);
	return (0);
}

int	get_color(char *line, t_game *game)
{
	char	**color;
	int		i;
	int		color_index;
	int		rgb[3];
	unsigned int	trgb;

	if (!line || !game)
		return (1);
	i = 1;
	while (ft_isspace(line[i]))
		i++;
	color_index = i;
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || line[i] == ',' || ft_isspace(line[i])))
		{
			// err: incorrect color format
			return (1);
		}
		i++;
	}
	color = ft_split(&line[color_index], ',');
	if (!color)
	{
		// err: no color
		return (1);
	}
	i = 0;
	while (color[i])
		i++;
	if (i > 3)
	{
		// err: incorrect color format
		return (1);
	}
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	free_array(color);
	if (!valid_range(rgb))
	{
		// err: invalid range
		return (1);
	}
	trgb = (rgb[0] >> 16 | rgb[1] >> 8 | rgb[2]);
	if (!strncmp(line, "F", 1))
		game->config.floor_color = trgb;
	else
		game->config.ceil_color = trgb;
	return (0);
}
