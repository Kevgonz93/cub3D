#include "../../includes/src.h"

/* función para determinar qué textura hay que usar */
static t_tex  *determine_texture(t_game *game, t_dda *dda)
{
    if (dda->side == 0)
    {
        if (dda->ray_dir_x > 0)
            /* el rayo ha golpeado una pared vertical y apunta a la derecha */
            return (&game->config.we);
        else
            /* el rayo ha golpeado una pared vertical y apunta a la izquierda */
            return (&game->config.ea);
    }
    else
    {
        if (dda->ray_dir_y > 0)
            /* el rayo ha golpeado una pared horizontal y apunta arriba */
            return (&game->config.no);
        else
            /* el rayo ha golpeado una pared horizontal y apunta abajo */
            return (&game->config.so);
    }
    return (NULL);
}

static double   find_texture_hit_coordinate(t_game *game, t_dda *dda, double dist_hit)
{
    double  wall_x;

    if (dda->side)
        wall_x = game->player.x + dist_hit * dda->ray_dir_x;
    else
        wall_x = game->player.y + dist_hit * dda->ray_dir_y;
    wall_x -= floor(wall_x); // proporción del ancho de la textura
    return (wall_x);
}

void	draw_wall_column_texturized(t_game *game, int x, double wall_height, t_dda *dda, double dist_hit)
{
	//double	start;
	//double	end;
	//int		y;
    t_tex   *texture;
    t_line  line;
    double  wall_x;
    unsigned int    pxl_color;
    
    // calcular el inicio y final de la pared en la Y de la pantalla
	line.start_y = (HEIGHT / 2.0) - (wall_height / 2.0);
	if (line.start_y < 0)
        line.start_y = 0;
	line.end_y = (HEIGHT / 2.0) + (wall_height / 2.0);
	if (line.end_y >= HEIGHT)
        line.end_y = HEIGHT - 1;
	//y = (int)start;
    texture = determine_texture(game, dda);
    //texture = &game->config.no;
    wall_x = find_texture_hit_coordinate(game, dda, dist_hit);
    line.tex_x = (int)(wall_x * texture->width);
	line.screen_y = (int)line.start_y;
    
    while (line.screen_y <= (int)line.end_y)
	{
        // compute y coordinate of texture
        line.tex_y = (int)((line.screen_y - line.start_y) * texture->height / wall_height);
        // get color from texture
        pxl_color = *(unsigned int *)(texture->addr + (line.tex_y * texture->line_len) + (line.tex_x * texture->bpp / 8));
        my_mlx_pixel_put(&game->img, x, line.screen_y, pxl_color);
		line.screen_y++;
	}
}
