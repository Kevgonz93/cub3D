/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:03:45 by kegonza           #+#    #+#             */
/*   Updated: 2025/12/18 18:43:46 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	update_angle(t_game *game, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		game->config.player_angle -= ROT_SPEED;
		game->keys[KEY_LEFT] = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->config.player_angle += ROT_SPEED;
		game->keys[KEY_RIGHT] = 1;
	}
	if (game->config.player_angle < 0)
		game->config.player_angle += 2 * PI;
	if (game->config.player_angle > 2 * PI)
		game->config.player_angle -= 2 * PI;
}

int	key_press(int keycode, t_game *game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
		return (game_exit(game, 0));
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		update_angle(game, keycode);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}
