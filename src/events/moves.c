/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:02:24 by akwadran          #+#    #+#             */
/*   Updated: 2026/02/04 18:32:55 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	rotate_player(t_game *game)
{
	if (game->keys[KEY_LEFT])
	{
		game->config.player_angle -= ROT_SPEED;
		if (game->config.player_angle < 0)
			game->config.player_angle += 2 * PI;
	}
	if (game->keys[KEY_RIGHT])
	{
		game->config.player_angle += ROT_SPEED;
		if (game->config.player_angle >= 2 * PI)
			game->config.player_angle -= 2 * PI;
	}
}

static void	add_forback_moves(t_game *game, float *dx, float *dy)
{
	float	angle;

	angle = game->config.player_angle;
	if (game->keys[KEY_W])
	{
		*dx += cos(angle) * MOVE_SPEED;
		*dy += sin(angle) * MOVE_SPEED;
	}
	if (game->keys[KEY_S])
	{
		*dx -= cos(angle) * MOVE_SPEED;
		*dy -= sin(angle) * MOVE_SPEED;
	}
}

static void	add_side_moves(t_game *game, float *dx, float *dy)
{
	float	angle;

	angle = game->config.player_angle;
	if (game->keys[KEY_A])
	{
		*dx += cos(angle - (PI / 2)) * MOVE_SPEED;
		*dy += sin(angle - (PI / 2)) * MOVE_SPEED;
	}
	if (game->keys[KEY_D])
	{
		*dx += cos(angle + (PI / 2)) * MOVE_SPEED;
		*dy += sin(angle + (PI / 2)) * MOVE_SPEED;
	}
}

void	move_player(t_game *game)
{
	float	dx;
	float	dy;

	dx = 0.0f;
	dy = 0.0f;
	add_forback_moves(game, &dx, &dy);
	add_side_moves(game, &dx, &dy);
	if (dx != 0.0f || dy != 0.0f)
		make_move(game, dx, dy);
}

void	update_player(t_game *game)
{
	if (game->exit_status.confirm_exit)
		return ;
	if (game->keys[KEY_LEFT] || game->keys[KEY_RIGHT])
		rotate_player(game);
	if (game->keys[KEY_W] || game->keys[KEY_S] || game->keys[KEY_A]
		|| game->keys[KEY_D])
		move_player(game);
}
