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
		game->config.no_tex = ft_substr(line, i, ft_strlen(&line[i]) - 1); // strlen - 1 para quitar '\n'
	else if (!strncmp(line, "SO", 2))
		game->config.so_tex = ft_substr(line, i, ft_strlen(&line[i]) - 1);
	else if (!strncmp(line, "WE", 2))
		game->config.we_tex = ft_substr(line, i, ft_strlen(&line[i]) - 1);
	else if (!strncmp(line, "EA", 2))
		game->config.ea_tex = ft_substr(line, i, ft_strlen(&line[i]) - 1);
	return (0);
}
