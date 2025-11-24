/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:04:11 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/24 14:45:04 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

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
