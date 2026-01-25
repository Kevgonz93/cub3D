/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:04:11 by kegonza           #+#    #+#             */
/*   Updated: 2026/01/25 21:43:40 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static void	draw_rect(t_img *img, int x, int y, int w, int h, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_exit_confirm(t_game *game)
{
	int	box_w;
	int	box_h;
	int	x;
	int	y;

	box_w = game->exit_status.width;
	box_h = game->exit_status.height;
	x = game->exit_status.x;
	y = game->exit_status.y;
	draw_rect(&game->img, x, y, box_w, box_h, 0x202020);
	draw_rect(&game->img, x, y, box_w, 2, 0xFFFFFF);
	draw_rect(&game->img, x, y + box_h - 2, box_w, 2, 0xFFFFFF);
	draw_rect(&game->img, x, y, 2, box_h, 0xFFFFFF);
	draw_rect(&game->img, x + box_w - 2, y, 2, box_h, 0xFFFFFF);
}

void	draw_exit_confirm_text(t_game *game)
{
	mlx_string_put(game->mlx, game->win, game->exit_status.x + 30,
		game->exit_status.y + 45, 0xFFFFFF,
		"Exit game?");
	mlx_string_put(game->mlx, game->win, game->exit_status.x + 30,
		game->exit_status.y + 75, 0xFFFFFF,
		"(Y)es   /   (N)o   (Esc = cancel)");
}

int	game_exit(t_game *game, int status)
{
	free_game(game, 0);
	exit(status);
	return (0);
}

int	close_window(t_game *game)
{
	return (game_exit(game, 0));
}
