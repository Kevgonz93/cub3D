#include "../../includes/src.h"

static int	validate_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' '))
		{
			printf("INCORRECT CHAR: %s\n", &line[i]); // QUITAR
			return (error("Map contains incorrect character"));
		}
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

static int	check_walls(char **lines, t_map *map)
{
	// por hacer
	(void)map;
	(void)lines;
	return (0);
}

int	validate_map(t_map *map)
{
	int	player;
	int	i;

	player = 0;
	//map_index = i;
	
	// SEPARAR EN OTRA FUNCIÓN
	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) > map->width)
			map->width = ft_strlen(map->grid[i]);
		if (validate_chars(map->grid[i]))
			return (1);
		player += find_player(map->grid[i]);
		i++;
	}
	if (player != 1)
		return (error("There must be exactly one player"));
	//fill_empty_spaces(map);
	check_walls(map->grid, map);
    return (0);
}
