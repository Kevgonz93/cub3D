/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_config_settings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:53:35 by akwadran          #+#    #+#             */
/*   Updated: 2026/01/24 17:54:46 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

void	init_tex(t_tex *tex)
{
	tex->path = NULL;
	tex->img = NULL;
	tex->addr = NULL;
	tex->bpp = 0;
	tex->endian = 0;
	tex->height = 0;
	tex->line_len = 0;
	tex->width = 0;
	tex->num = 0;
}

void	init_config(t_config *config)
{
	init_tex(&config->no);
	init_tex(&config->so);
	init_tex(&config->we);
	init_tex(&config->ea);
	config->floor_color = 0;
	config->floor_color_found = false;
	config->ceil_color = 0;
	config->ceil_color_found = false;
	config->fov = PI / 3;
	config->player_angle = 0;
	config->map = NULL;
}
