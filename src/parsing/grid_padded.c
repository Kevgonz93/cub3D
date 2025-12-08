#include "../../includes/src.h"
/*
static void	fill_out_line_padded(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	while (i < map->width + 2)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
}
*/

/*
static char	*cpy_line_padded(char *grid_line, t_map *map)
{
	char	*grid_padded_line;
	size_t	len;

	grid_padded_line = (char *)malloc(sizeof(char) * (map->width + 3));
	if (!grid_padded_line)
		return(NULL);
	grid_line[0] = ' ';
    len = ft_strlen(grid_line);
	ft_strlcpy(&grid_padded_line[1], grid_line, len + 1);
	grid_padded_line[len + 1] = ' ';
	grid_padded_line[len + 2] = '\0';
	printf("COPIED PADDED LINE: >%s<\n", grid_padded_line);
	return (grid_padded_line);
}

static char	*get_empty_line(t_map *map)
{
	char	*grid_line;
	int	i;

	grid_line = (char *)malloc(sizeof(char) * (map->width + 3));
	if (!grid_line)
		return(NULL);
	i = 0;
	while (i < map->width + 2)
	{
		grid_line[i] = ' ';
		i++;
	}
	grid_line[i] = '\0';
	return (grid_line);
}

char **get_grid_padded(t_map *map)
{
	char	**grid_padded;
	int	i;

	grid_padded = (char **)malloc(sizeof(char *) * (map->height + 3));
	if (!grid_padded)
		return (NULL);
	grid_padded[0] = get_empty_line(map);
	if (!grid_padded[0])
		return (NULL);
	i = 0;
	while (map->grid && map->grid[i])
	{
		grid_padded[i + 1] = cpy_line_padded(map->grid[i], map); ///////////
		if (!grid_padded[i + 1])
			return (NULL);
		i++;
	}
	grid_padded[i + 1] = get_empty_line(map);
	grid_padded[i + 2] = NULL;
	return (grid_padded);
}
*/

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
