#include "../../includes/src.h"

static t_tex	*determine_texture(t_game *game, t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->ray_dir_x > 0)
			return (&game->config.we);
		return (&game->config.ea);
	}
	if (dda->ray_dir_y > 0)
		return (&game->config.no);
	return (&game->config.so);
}

static double	find_texture_hit_coordinate(t_game *game,
			t_dda *dda, double dist_hit)
{
	double	wall_x;
	double	pos_x;
	double	pos_y;

	pos_x = game->player.x / (double)TILE_SIZE;
	pos_y = game->player.y / (double)TILE_SIZE;
	if (dda->side == 0)
		wall_x = pos_y + dist_hit * dda->ray_dir_y;
	else
		wall_x = pos_x + dist_hit * dda->ray_dir_x;
	wall_x -= floor(wall_x); // proporción del ancho de la textura
	return (wall_x);
}

void	draw_wall_column_texturized(t_game *game, int x, double wall_height,
		t_dda *dda, double dist_hit)
{
	t_tex			*texture;
	double			wall_x;
	int				draw_start;
	int				draw_end;
	double			step;
	double			tex_pos;
	int				y;
	int				tex_x;
	int				tex_y;
	unsigned int	pxl_color;
	double			start_y;

	start_y = (HEIGHT / 2.0) - (wall_height / 2.0);
	draw_start = (int)start_y;
	draw_end = (int)((HEIGHT / 2.0) + (wall_height / 2.0));
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	texture = determine_texture(game, dda);
	wall_x = find_texture_hit_coordinate(game, dda, dist_hit);
	tex_x = (int)(wall_x * (double)texture->width);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	step = (double)texture->height / wall_height;
	tex_pos = (draw_start - start_y) * step;
	y = draw_start;
	while (y <= draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)texture->height)
			tex_y = (int)texture->height - 1;
		pxl_color = *(unsigned int *)(texture->addr
				+ (tex_y * texture->line_len)
				+ (tex_x * texture->bpp / 8));
		my_mlx_pixel_put(&game->img, x, y, pxl_color);
		tex_pos += step;
		y++;
	}
}
