#include "../../includes/src.h"

static int    load_texture(t_game *game, t_tex *tex, char *path)
{
    if (!game->mlx || !path)
        return (error("Can´t load textures"));
    //tex->img = mlx_png_file_to_image(game->mlx, path, &tex->width, &tex->height);
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
