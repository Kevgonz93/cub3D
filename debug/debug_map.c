#include "../includes/src.h"

int draw_tile(t_game *game, int x, int y, unsigned int color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE)
    {
        j = 0;
        while (j < TILE)
        {
            my_mlx_pixel_put(&game->img, x + i, y + j, color);
            j++;
        }
        i++;
    }
    return (0);
}

int render_2d_map(t_game *game)
{
	int			x;
	int			y;
    t_map   *map;
    int         aux_y;

	map = game->config.map;
    y = 0;
	while (y < map->height)
	{
        x = 0;
		while (x < map->width)
		{
            aux_y = HEIGHT - (map->height * TILE) + (y * TILE);
			if (map->grid[y][x] == '1')
				draw_tile(game, x * TILE, aux_y, (0 << 16 | 0 << 8 | 205));
			else if (map->grid[y][x] == '0')
                draw_tile(game, x * TILE, aux_y, (250 << 16 | 235 << 8 | 215));
            else if (map->grid[y][x] == 'S' || map->grid[y][x] == 'N'
                || map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
                draw_tile(game, x * TILE, aux_y, (128 << 16 | 0 << 8 | 0));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
