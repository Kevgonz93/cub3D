#include "../../includes/src.h"

void	paint_background(t_game *game)
{
	int			x;
	int			y;
	t_config	*config;

	y = 0;
	config = &game->config;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(&game->img, x, y, config->ceil_color);
			else
				my_mlx_pixel_put(&game->img, x, y, config->floor_color);
			x++;
		}
		y++;
	}
}
