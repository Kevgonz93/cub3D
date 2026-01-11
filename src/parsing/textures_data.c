#include "../../includes/src.h"

static int    load_texture(t_game *game, t_tex *tex, char *path)
{
    if (!game->mlx || !path)
        return (error("Can´t load textures"));
    tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
    if (!tex->img)
        return (error("IMG can´t be created"));
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
    if (!tex->addr)
        return (error("ADDR can´t be created"));
    return (0);
}

int    init_textures(t_game *game)
{
    if (load_texture(game, &game->config.no, game->config.no_tex))
        return (1);
    if (load_texture(game, &game->config.so, game->config.so_tex))
        return (1); 
    if (load_texture(game, &game->config.we, game->config.we_tex))
        return (1);
    if (load_texture(game, &game->config.ea, game->config.ea_tex))
        return (1);
    return (0);
}

void	draw_wall_column_texturized(t_game *game, int x, double wall_height, t_dda *dda)
{
	//dda;
	double	start;
	double	end;
	int		y;
    t_tex   texture;

	start = (HEIGHT / 2.0) - (wall_height / 2.0);
	if (start < 0)
		start = 0;
	end = (HEIGHT / 2.0) + (wall_height / 2.0);
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = (int)start;

    if (dda->side == 0)
    {
        if (dda->ray_dir_x > 0)
            texture = game->config.we;
        else
            texture = game->config.ea;
    }
    else
    {
        if (dda->ray_dir_y > 0)
            texture = game->config.no;
        else
            texture = game->config.so;
    }
    (void)texture;
	while (y <= (int)end)
	{
		my_mlx_pixel_put(&game->img, x, y, 0xFF93FF);
		y++;
	}
}