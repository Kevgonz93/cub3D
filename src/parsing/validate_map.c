#include "../../includes/src.h"

static int	validate_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' '))
			return (error("Map contains incorrect character"));
		i++;
	}
	return (0);
}

static int	find_player(char *line)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (line[i])
	{
		if (line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W')
			player++;
		i++;
	}
	return (player);
}

static int	check_walls(char **grid, int x, int y, int height, int width)
{
	if (x < 0 || x >= width || y < 0 || y >= height || grid[y][x] == '1'
		|| grid [y][x] == 'x')
		return (1);
	else if (grid[y][x] == '0' || grid[y][x] == 'N' || grid[y][x] == 'S'
		|| grid[y][x] == 'E' || grid[y][x] == 'W')
		return (0);
	else
	{
		grid[y][x] = 'x';
		return (check_walls(grid, x - 1, y, height, width)
		&& check_walls(grid, x, y - 1, height, width)
		&& check_walls(grid, x + 1, y, height, width)
		&& check_walls(grid, x, y + 1, height, width));
	}
}

int	validate_map(t_map *map)
{
	int	player;
	int	i;
	char	**grid_padded;

	player = 0;
	i = 0;
	while (map->grid[i])
	{
		if (validate_chars(map->grid[i]))
			return (1);
		player += find_player(map->grid[i]);
		i++;
	}
	if (player != 1)
		return (error("There must be exactly one player"));
	grid_padded = get_grid_padded(map);
	if (!grid_padded)
		return (error("Grid padded: Malloc failed"));
	if (!check_walls(grid_padded, 0, 0, map->height + 2, map->width + 2))
    {
		free_array(grid_padded);
    	return (error("Map must be closed with walls"));
    }
	free_array(grid_padded);
	return (0);
}
