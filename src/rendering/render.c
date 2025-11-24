/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:04:44 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/24 14:41:12 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

int	render_frame(t_game *game)
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
	y = HEIGHT / 4;
	while (y < 3 * HEIGHT / 4)
	{
		my_mlx_pixel_put(&game->img, WIDTH / 2 - 1, y, 0xFF0000);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
