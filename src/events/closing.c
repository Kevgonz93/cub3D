/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:04:11 by kegonza           #+#    #+#             */
/*   Updated: 2026/02/04 18:26:32 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static void	draw_rect(t_img *img, t_draw *draw, int border, int color)
{
	int	i;
	int	j;

	i = draw->y;
	while (i < draw->y + draw->h)
	{
		j = draw->x;
		while (j < draw->x + draw->w)
		{
			if (border)
			{
				if (i == draw->y || i == draw->y + draw->h - 1
					|| j == draw->x || j == draw->x + draw->w - 1)
					my_mlx_pixel_put(img, j, i, color);
			}
			else
				my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_exit_confirm(t_game *game)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	draw->x = game->exit_status.x;
	draw->y = game->exit_status.y;
	draw->w = game->exit_status.width;
	draw->h = game->exit_status.height;
	draw_rect(&game->img, draw, 0, 0x202020);
	draw_rect(&game->img, draw, 2, 0xFFFFFF);
	draw_rect(&game->img, draw, 0, 0x202020);
	draw_rect(&game->img, draw, 2, 0xFFFFFF);
	draw_rect(&game->img, draw, 0, 0x202020);
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
