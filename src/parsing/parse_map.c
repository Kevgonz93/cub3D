#include "../../includes/src.h"
/*
static void	fill_out_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	while (i < map->width)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
}
*/
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
/*
static char	*cpy_line(char *buffer_line, t_map *map)
{
	char	*grid_line;
	size_t	len;

	grid_line = (char *)malloc(sizeof(char) * (map->width + 1));
	if (!grid_line)
		return(error("Grid: Malloc failed"), NULL);
	len = ft_strlen(buffer_line);
	if (buffer_line[len - 1] == '\n')
		len--;
	ft_strlcpy(grid_line, buffer_line, len + 1);
	if ((int)ft_strlen(grid_line) < map->width)
		fill_out_line(grid_line, map);
	return (grid_line);
		
}
*/
static char	*cpy_line_padded(char *buffer_line, t_map *map)
{
	char	*grid_line;
	size_t	len;

	grid_line = (char *)malloc(sizeof(char) * (map->width + 3));
	if (!grid_line)
		return(error("Grid: Malloc failed"), NULL);
	len = ft_strlen(buffer_line);
	if (buffer_line[len - 1] == '\n')
		len--;
	grid_line[0] = ' ';
	ft_strlcpy(&grid_line[1], buffer_line, len + 1);
	grid_line[len + 1] = ' ';
	grid_line[len + 2] = '\0';
	if ((int)ft_strlen(grid_line) < map->width + 2)
		fill_out_line_padded(grid_line, map);
	return (grid_line);
}

static char	*get_empty_line(t_map *map)
{
	char	*grid_line;
	int	i;

	grid_line = (char *)malloc(sizeof(char) * (map->width + 3));
	if (!grid_line)
		return(error("Grid: Malloc failed"), NULL);
	i = 0;
	while (i < map->width + 2)
	{
		grid_line[i] = ' ';
		i++;
	}
	grid_line[i] = '\0';
	return (grid_line);
}

static int	get_grid_padded(char **buffer, t_map *map, int map_index)
{
	char	**grid;
	int	i;

	grid = (char **)malloc(sizeof(char *) * (map->height + 3));
	if (!grid)
		return (error("Grid: Malloc failed"));
	grid[0] = get_empty_line(map);
	if (!grid[0])
		return (1);
	i = 1;
	while (buffer[map_index])
	{
		grid[i] = cpy_line_padded(buffer[map_index], map);
		if (!grid[i])
			return (1);
		i++;
		map_index++;
	}
	grid[i] = get_empty_line(map);
	grid[i + 1] = NULL;
	map->grid = grid;
	return (0);
}
/*
static int	get_grid(char **buffer, t_map *map, int map_index)
{
	char	**grid;
	int	i;

	grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!grid)
		return (error("Grid: Malloc failed"));
	i = 0;
	while (buffer[map_index])
	{
		grid[i] = cpy_line(buffer[map_index], map);
		if (!grid[i])
			return (1);
		i++;
		map_index++;
	}
	grid[i] = NULL;
	map->grid = grid;
	return (0);
}
*/
static int	get_dimensions(char **buffer, t_map *map, int map_index)
{
	int	tmp;
	
	map->height = 0;
	map->width = 0;
	while (buffer[map_index])
	{
		map->height++;
		tmp = ft_strlen(buffer[map_index]);
		if (buffer[map_index][ft_strlen(buffer[map_index]) - 1] == '\n')
			tmp--;
		if (tmp > map->width)
			map->width = tmp;
		map_index++;
	}
	if (map->height == 0 || map->width == 0)
		return (error("Empty map"));
	return (0);
}

int	parse_map(char **buffer, t_game *game, int map_index)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (error("Map: Malloc failed"));
	while (!strcmp(buffer[map_index], "\n"))
		map_index++;
	if (get_dimensions(buffer, map, map_index))
		return (1);
	/*if (get_grid(buffer, map, map_index))
		return (1);*/
	if (get_grid_padded(buffer, map, map_index))
		return (1);
	/*if (validate_map(map))
		return (1);*/
	//print_array(map->grid);
	game->config.map = map;
	return (0);
}
