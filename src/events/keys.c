/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:03:45 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/24 14:45:09 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

int	key_press(int keycode, t_game *game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
		return (game_exit(game, 0));
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}
