#include "../../includes/cub3d.h"

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		j;
	char	*new_str;

	if (!dst)
		return (ft_strdup(src));
	if (!src)
		return (NULL);
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(dst) + ft_strlen(src) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (dst[i])
	{
		new_str[i] = dst[i];
		i++;
	}
	while (src[j])
		new_str[i++] = src[j++];
	new_str[i] = '\0';
	free(dst);
	return (new_str);
}

char	*make_full_line(int width, char c)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (width + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < width)
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*make_padding_line(char *old_line, int new_width)
{
	char	*new_line;
	int		i;

	if (!old_line || new_width < 2)
		return (NULL);
	new_line = make_full_line(new_width, '1');
	if (!new_line)
	{
		printf("Error allocating memory for padding line\n");
		return (NULL);
	}
	i = 0;
	while (old_line[i] && i < new_width - 2)
	{
		new_line[i + 1] = old_line[i];
		i++;
	}
	return (new_line);
}

void	paddeding_map(t_game *game)
{
	int		old_height;
	int		new_width;
	int		new_height;
	char	**new_grid;
	int		i;

	old_height = game->config.map->height;
	new_width = game->config.map->width + 2;
	new_height = old_height + 2;
	new_grid = NULL;
	new_grid = (char **)malloc(sizeof(char *) * (new_height + 1));
	if (!new_grid)
		return ;
	new_grid[0] = make_full_line(new_width, '1');
	if (!new_grid[0])
	{
		printf("Error allocating memory for map padding\n");
		free_array(new_grid);
		return ;
	}
	i = 0;
	while (++i <= old_height)
	{
		new_grid[i] = make_padding_line(game->config.map->grid[i - 1],
				new_width);
		if (!new_grid[i])
		{
			printf("Error allocating memory for map padding\n");
			free_array(new_grid);
			return ;
		}
	}
	new_grid[new_height - 1] = make_full_line(new_width, '1');
	if (!new_grid[new_height - 1])
	{
		printf("Error allocating memory for map padding\n");
		free_array(new_grid);
		return ;
	}
	new_grid[new_height] = NULL;
	free_array(game->config.map->grid);
	game->config.map->grid = new_grid;
	game->config.map->width = new_width;
	game->config.map->height = new_height;
}
