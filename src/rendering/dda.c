/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:01:18 by akwadran          #+#    #+#             */
/*   Updated: 2026/02/04 19:17:26 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/src.h"

static void	get_side_dists(t_dda *dda, double pos_x, double pos_y)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - pos_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - pos_y) * dda->delta_dist_y;
	}
}

static int	is_wall_at(t_game *game, int mx, int my)
{
	int		len;
	char	c;

	if (my < 0 || my >= game->config.map->height)
		return (1);
	len = (int)ft_strlen(game->config.map->grid[my]);
	if (mx < 0 || mx >= len)
		return (1);
	c = game->config.map->grid[my][mx];
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

static void	pre_dda(t_game *game, double ray_angle, t_dda *dda)
{
	double	pos_x;
	double	pos_y;

	dda->ray_dir_x = cos(ray_angle);
	dda->ray_dir_y = sin(ray_angle);
	pos_x = game->player.x / (double)TILE_SIZE;
	pos_y = game->player.y / (double)TILE_SIZE;
	dda->map_x = (int)pos_x;
	dda->map_y = (int)pos_y;
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	get_side_dists(dda, pos_x, pos_y);
}

void	run_dda(t_game *game, double ray_angle, t_dda *dda)
{
	pre_dda(game, ray_angle, dda);
	dda->hit = 0;
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (is_wall_at(game, dda->map_x, dda->map_y))
			dda->hit = 1;
	}
}
