#include "include/cub3d.h"

static int  get_buffer_size(char *file)
{
    int     fd;
    int     size;
    char    tmp[1];

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (error("Map can´t be opened"));
    size = 0;
    while (read(fd, &tmp, sizeof(char)) > 0)
        size++;
    close(fd);
    return (++size);
}

static char *create_buffer(char *file)
{
    int     fd;
    char    *buffer;
    int     buffer_size;

    buffer_size = get_buffer_size(file);
    if (buffer_size == -1)
        return (-1);
    buffer = (char *)malloc(sizeof(char) * buffer_size);
    if (!buffer)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (error("Map can´t be opened"));
    read(fd, buffer, buffer_size);
    printf("BUFFER:\n%s\n", buffer); // QUITAR
    return(buffer);
}

int parse_file(char *file, t_game *game)
{
    char    *buffer;
    int     i;

    (void)game;

    buffer = create_buffer(file);
    if (!buffer)
        return(error("Malloc failed"));
    i = 0;
    /*
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            i++;
        else if (buffer[i] == 'N')
            get_no_tex(&buffer[i]);
        else if (buffer[i] == 'S')
            get_so_tex(&buffer[i]);
        else if (buffer[i] == 'W')
            get_we_tex(&buffer[i])
    
    }
    */     
    
    /*
    game->config.no_tex;
    game->config.so_tex;
    game->config.we_tex;
    game->config.ea_tex;
    game->config.floor_color;
    game->config.ceil_color;
    game->config.map;
    */
   free(buffer);
   return (0);
}
