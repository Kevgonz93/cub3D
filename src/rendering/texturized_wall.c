/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturized_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:11 by akwadran          #+#    #+#             */
/*   Updated: 2026/02/04 18:24:06 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	wall_x -= floor(wall_x);
	return (wall_x);
}

static void	draw_loop(t_column *col, t_tex *texture, t_game *game, int x)
{
	unsigned int	pxl_color;

	while (col->y <= col->draw_end)
	{
		col->tex_y = (int)col->tex_pos;
		if (col->tex_y < 0)
			col->tex_y = 0;
		if (col->tex_y >= (int)texture->height)
			col->tex_y = (int)texture->height - 1;
		pxl_color = *(unsigned int *)(texture->addr
				+ (col->tex_y * texture->line_len)
				+ (col->tex_x * texture->bpp / 8));
		my_mlx_pixel_put(&game->img, x, col->y, pxl_color);
		col->tex_pos += col->step;
		col->y++;
	}
}

void	draw_wall_column_texturized(t_game *game, int x, double wall_height,
		t_dda *dda)
{
	t_tex			*texture;
	t_column		col;

	col.start_y = (HEIGHT / 2.0) - (wall_height / 2.0);
	col.draw_start = (int)col.start_y;
	col.draw_end = (int)((HEIGHT / 2.0) + (wall_height / 2.0));
	if (col.draw_start < 0)
		col.draw_start = 0;
	if (col.draw_end >= HEIGHT)
		col.draw_end = HEIGHT - 1;
	texture = determine_texture(game, dda);
	col.wall_x = find_texture_hit_coordinate(game, dda, dda->raw_dist);
	col.tex_x = (int)(col.wall_x * (double)texture->width);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		col.tex_x = texture->width - col.tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		col.tex_x = texture->width - col.tex_x - 1;
	col.step = (double)texture->height / wall_height;
	col.tex_pos = (col.draw_start - col.start_y) * col.step;
	col.y = col.draw_start;
	draw_loop(&col, texture, game, x);
}
