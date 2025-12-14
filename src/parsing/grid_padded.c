#include "../../includes/src.h"

static char	*cpy_line_padded(char *grid, t_map *map)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (map->width + 3));
	if (!line)
		return (NULL);
	line[0] = ' ';
	i = 0;
	while (i < map->width)
	{
		line[i + 1] = grid[i];
		i++;
	}
	line[i + 1] = ' ';
	line[i + 2] = '\0';
	return (line);
}

static char	*get_empty_line(t_map *map)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * map->width + 3);
	if (!line)
		return (NULL);
	i = 0;
	while (i < map->width + 2)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**get_grid_padded(t_map *map)
{
	char	**grid_padded;
	int		i;

	grid_padded = (char **)malloc(sizeof(char *) * (map->height + 3));
	if (!grid_padded)
		return (NULL);
	grid_padded[0] = get_empty_line(map);
	if (!grid_padded[0])
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		grid_padded[i + 1] = cpy_line_padded(map->grid[i], map);
		if (!grid_padded[i + 1])
			return (NULL);
		i++;
	}
	grid_padded[i + 1] = get_empty_line(map);
	grid_padded[i + 2] = NULL;
	return (grid_padded);
}
