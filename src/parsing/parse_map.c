#include "../../includes/src.h"
/*
static char	*rm_trailing_newline(char *line)
{
	char	*new;

	if (line[ft_strlen(line) - 1] == '\n')
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(new, line, ft_strlen(line));
	}
	else
		new = ft_strdup(line);
	return (new);
}
*//*
static int	get_grid(char **lines, int map_index, t_map *map)
{
	int	i;
	char	**grid;

	map->height = 0;
	i = map_index;
	while (lines[i])
	{
		map->height++;
		i++;
	}
	if (map->height == 0)
		return (error("Empty map"));
	grid = (char**)malloc(sizeof(char *) * map->height + 1);
	if (!grid)
		return (error("Grid: Malloc failed"));
	i = 0;
	while (lines[map_index])
	{
		grid[i] = rm_trailing_newline(lines[map_index]);
		i++;
		map_index++;
	}
	grid[i] = NULL;
	map->grid = grid;
	return (0);
}*/

static void	fill_out_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	while (i < (map->width - 1))
	{
		line[i] = ' ';
		i++;
	}
}

static char	*cpy_line(char *buffer_line, t_map *map)
{
	char	*grid_line;
	size_t	len;

	grid_line = (char *)malloc(sizeof(char) * (map->width + 1));
	if (!grid_line)
		return(error("Grid: Malloc failed"), NULL);
	len = ft_strlen(buffer_line);
	if (buffer_line[ft_strlen(buffer_line) - 1] == '\n')
		len--;
	ft_strlcpy(grid_line, buffer_line, len);
	if ((int)ft_strlen(grid_line) < map->width)
		fill_out_line(grid_line, map);
	return (grid_line);
		
}

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
	map->grid = grid;
	return (0);
}
/*
static int	fill_empty_spaces(t_map *map)
{
	int	i;
	char	*tmp;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) < map->width)
		{
			tmp = (char *)malloc(sizeof(char) * (map->width + 1));
			ft_strlcpy(tmp, map->grid[i], ft_strlen(map->grid[i]));
			j = ft_strlen(map->grid[i]);
			while (j < map->width)
			{
				tmp[j] = ' ';
				j++;
			}
			tmp[j] = '\0';
			free(map->grid[i]);
			map->grid[i] = tmp;
		}
		i++;
	}
	return (0);
}
*/
static int	get_height(char **buffer, t_map *map, int map_index)
{
	map->height = 0;
	while (buffer[map_index])
	{
		map->height++;
		map_index++;
	}
	if (map->height == 0)
		return (error("Empty map"));
	return (0);
}

static int	get_width(char **buffer, t_map *map, int map_index)
{ 
	int	tmp;

	map->width = 0;
	while (buffer[map_index])
	{
		tmp = ft_strlen(buffer[map_index]);
		if (buffer[map_index][ft_strlen(buffer[map_index]) - 1] == '\n')
			tmp--;
		if (tmp > map->width)
			map->width = tmp;
		map_index++;
	}
	if (map->width == 0)
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
	if (get_height(buffer, map, map_index))
		return (1);
	if (get_width(buffer, map, map_index))
		return (1);
	if (get_grid(buffer, map, map_index))
		return (1);
	/*if (validate_map(map))
		return (1);*/
	//print_array(map->grid);
	game->config.map = map;
	return (0);
}
