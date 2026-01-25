/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inittial_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:12:43 by kegonza           #+#    #+#             */
/*   Updated: 2026/01/25 21:40:35 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	init_exit_conf(t_exit *exit_conf)
{
	exit_conf->confirm_exit = false;
	exit_conf->width = 420;
	exit_conf->height = 120;
	exit_conf->x = (WIDTH - exit_conf->width) / 2;
	exit_conf->y = (HEIGHT - exit_conf->height) / 2;
	exit_conf->color_box = 0x202020;
	exit_conf->color_text = 0xFFFFFF;
}

void	init_game(t_game *game)
{
	int	key;

	game->mlx = NULL;
	game->win = NULL;
	init_img(&game->img);
	init_config(&game->config);
	init_player(&game->player);
	key = 0;
	while (key < 65364)
	{
		game->keys[key] = 0;
		key++;
	}
	init_exit_conf(&game->exit_status);
}
