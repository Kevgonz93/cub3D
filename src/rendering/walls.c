#include "../../includes/src.h"

// Devuelve el ángulo del rayo para la columna x.
// 1) player_angle: ángulo de la dirección del jugador.
// 2) initial_fov_angle: borde izquierdo del FOV
//    (ángulo del jugador - FOV/2).
// 3) proportion_of_screen: mapea x al rango [0, 1) en la pantalla.
// 4) where_in_fov: desplazamiento angular dentro del FOV según x.
// El resultado es el ángulo concreto del rayo que pasa por la
// columna x de la pantalla.

static double	get_angle(t_game *game, int x)
{
	double	initial_fov_angle;
	double	proportion_of_screen;
	double	where_in_fov;

	initial_fov_angle = game->config.player_angle - (game->config.fov / 2);
	proportion_of_screen = (double)x / (double)(WIDTH - 1);
	where_in_fov = proportion_of_screen * game->config.fov;
	return (initial_fov_angle + where_in_fov);
}

static double	get_height_wall(double dist_corrected, t_game *game)
{
	double	plane_dist;
	double	wall_height;

	plane_dist = (WIDTH / 2.0) / tan(game->config.fov / 2.0);
	wall_height = (1.0 / dist_corrected) * plane_dist;
	return (wall_height);
}

void	draw_wall_column(t_game *game, int x, double wall_height, t_dda *dda)
{
	(void)dda;
	double	start;
	double	end;
	int		y;

	start = (HEIGHT / 2.0) - (wall_height / 2.0);
	if (start < 0)
		start = 0;
	end = (HEIGHT / 2.0) + (wall_height / 2.0);
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = (int)start;
	while (y <= (int)end)
	{
		my_mlx_pixel_put(&game->img, x, y, 0xFF93FF);
		y++;
	}
}

double	get_dist_hit_raw(t_game *game, t_dda *dda)
{
	double	dist_hit;
	double	pos_x;
	double	pos_y;

	pos_x = game->player.x / (double)TILE_SIZE;
	pos_y = game->player.y / (double)TILE_SIZE;
	if (dda->side == 0)
		dist_hit = (dda->map_x - pos_x
				+ (1 - dda->step_x) / 2) / dda->ray_dir_x;
	else
		dist_hit = (dda->map_y - pos_y
				+ (1 - dda->step_y) / 2) / dda->ray_dir_y;
	return (dist_hit);
}

void	render_walls(t_game *game)
{
	int		x;
	double	ray_angle;
	t_dda	dda;
	double	raw_dist;
	double	correct_dist;
	double	wall_height;

	x = 0;
	while (x < WIDTH)
	{
		ray_angle = get_angle(game, x);
		run_dda(game, ray_angle, &dda);
		raw_dist = get_dist_hit_raw(game, &dda);
		correct_dist = raw_dist * cos(ray_angle - game->config.player_angle);
		if (correct_dist < 0.00001)
			correct_dist = 0.00001;
		wall_height = get_height_wall(correct_dist, game);
		draw_wall_column_texturized(game, x, wall_height, &dda, raw_dist);
		x++;
	}
}

// pseudocódigo de raycasting básico
// for (x = 0; x < WIDTH; x++)
// {
//     calcular ángulo ✅
//     raycast DDA ✅
//     calcular distancia
//     calcular altura del muro
//     dibujar columna
// }
