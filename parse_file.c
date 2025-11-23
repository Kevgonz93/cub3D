#include "include/cub3d.h"

static size_t  get_buffer_size(int fd)
{
    size_t  size;


}

int parse_file(char *file, t_game *game)
{
    int     fd;
    char    *buffer;
    size_t  buffer_size;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (error("Map can´t be opened"));
    
    game->config.no_tex;
    game->config.so_tex;
    game->config.we_tex;
    game->config.ea_tex;
    game->config.floor_color;
    game->config.ceil_color;
    game->config.map;

}
