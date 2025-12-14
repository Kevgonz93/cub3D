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
		{
			// err: incorrect color format
			return (0);
		}
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
		return (error("Incorrect color format"));
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	//printf("RGB: %d,%d,%d\n", rgb[0], rgb[1], rgb[2]);
	free_array(color);
	if (!valid_range(rgb))
		return (error("Incorrect color format"));
	*trgb = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	return (0);
}

int	get_color(char *line, t_game *game)
{
	int		i;
	int		color_index;
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
	if (!strncmp(line, "F", 1))
		game->config.floor_color = trgb;
	else
		game->config.ceil_color = trgb;
	return (0);
}
