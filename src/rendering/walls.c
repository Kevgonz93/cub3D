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

static double	get_dist_hit(t_game *game, double ray_angle, t_dda *dda)
{
	double	dist_hit;
	double	correct_dist;

	if (dda->side == 0)
		dist_hit = (dda->map_x - game->player.x
				+ (1 - dda->step_x) / 2) / dda->ray_dir_x;
	else
		dist_hit = (dda->map_y - game->player.y
				+ (1 - dda->step_y) / 2) / dda->ray_dir_y;
	correct_dist = dist_hit * cos(ray_angle - game->config.player_angle);
	if (correct_dist < 0.00001)
		correct_dist = 0.00001;
	return (correct_dist);
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
// FUNCIÓN PARA PINTAR LAS PAREDES EN ROJO (PARA PRUEBAS)
void	paint_walls(t_game *game)
{
	int			x;

	x = HEIGHT / 4;
	while (x < 3 * HEIGHT / 4)
	{
		my_mlx_pixel_put(&game->img, WIDTH / 2 - 1, x, 0xFF0000);
		x++;
	}
}

void	render_walls(t_game *game)
{
	int		x;
	double	ray_angle;
	t_dda	dda;
	double	dist_hit;
	double	wall_height;

	// game->config.player_angle = atan2(game->player.dir_y, game->player.dir_x);
	x = 0;
	while (x < WIDTH)
	{
		ray_angle = get_angle(game, x);
		run_dda(game, ray_angle, &dda);
		dist_hit = get_dist_hit(game, ray_angle, &dda);
		wall_height = get_height_wall(dist_hit, game);
		draw_wall_column(game, x, wall_height, &dda);
		draw_wall_column_texturized(game, x, wall_height, &dda, dist_hit);
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
