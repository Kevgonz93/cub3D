/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:03:45 by kegonza           #+#    #+#             */
/*   Updated: 2025/12/19 12:35:14 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

int	key_press(int keycode, t_game *game)
{
	bool	exit_status;

	printf("Key pressed: %d\n", keycode);
	while (1)
	{
		exit_status = game->exit_status.confirm_exit;
		if (keycode == KEY_ESC)
		{
			if (!exit_status)
				game->exit_status.confirm_exit = true;
			else
				game->exit_status.confirm_exit = false;
			return (0);
		}
		if (exit_status)
		{
			if (keycode == KEY_Y)
				return (game_exit(game, 0));
			if (keycode == KEY_N || keycode == KEY_ESC)
				game->exit_status.confirm_exit = 0;
			return (0);
		}
		if (keycode >= 0 && keycode < 256)
			game->keys[keycode] = 1;
		return (0);
	}
}

int	key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < 256)
		game->keys[keycode] = 0;
	return (0);
}
