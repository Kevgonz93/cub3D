#include "../../includes/src.h"

	// Calcula step_x/step_y (dirección en el mapa) y side_dist_x/side_dist_y
	// (distancia desde la posición del jugador hasta el primer lado de celda
	// que el rayo va a cruzar en X e Y).
	//
	// En X:
	//  - Si ray_dir_x < 0, el rayo va hacia la izquierda. El primer lado que
	//    cruzará es el borde izquierdo de la celda actual (map_x), así que la
	//    distancia es player.x - map_x.
	//  - Si ray_dir_x > 0, el rayo va hacia la derecha. El primer lado es el
	//    borde derecho (map_x + 1.0), distancia map_x + 1.0 - player.x.
	// Esa distancia se multiplica por delta_dist_x para llevarla a la escala
	// del DDA.
	//
	// En Y es exactamente la misma idea pero con filas (map_y) y ray_dir_y.

	// Si el rayo apunta hacia la izquierda
	// La posición del jugador será mayor que la del mapa en x
	// por eso se resta para calcular la distancia al siguiente lado
	// luego se multiplica por delta_dist_x para hacerla proporcional

	// Si el rayo apunta hacia la derecha
	// La posición del jugador será menor que la del mapa en x
	// por eso se suma 1.0 para calcular la distancia al siguiente lado
	// luego se multiplica por delta_dist_x para hacerla proporcional

static void	get_side_dists(t_game *game, t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player.x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->player.x)
			* dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player.y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->player.y)
			* dda->delta_dist_y;
	}
}

// Inicializa los parámetros necesarios antes de ejecutar el DDA:
//  - ray_dir_x/y: vector dirección del rayo a partir de su ángulo.
//  - map_x/y: celda del mapa en la que está el jugador (floor implícito).
//  - delta_dist_x/y: distancia que recorre el rayo para cruzar una
//    celda completa en X o en Y (normalizada).
// Luego llama a get_side_dists para obtener step_x/y y side_dist_x/y.

static void	pre_dda(t_game *game, double ray_angle, t_dda *dda)
{
	dda->ray_dir_x = cos(ray_angle);
	dda->ray_dir_y = sin(ray_angle);
	dda->map_x = (int)game->player.x;
	dda->map_y = (int)game->player.y;
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	get_side_dists(game, dda);
}

// el dda es un algoritmo que permite trazar un rayo en un mapa de cuadrícula
// y determinar qué celdas de la cuadrícula atraviesa el rayo.
// se utiliza para detectar colisiones con paredes en juegos 3D basados en raycasting.
// el algoritmo funciona avanzando paso a paso a lo largo del rayo
// y calculando las distancias a los próximos lados de las celdas en ambas direcciones (x e y).

// esta función implementa el bucle principal del algoritmo DDA
// que continúa hasta que el rayo golpea una pared.
// en cada iteración del bucle, se compara la distancia al próximo lado en x
// con la distancia al próximo lado en y.
// el lado con la distancia más corta determina la dirección en la que se avanza el rayo.
// si el lado x es más cercano, se actualiza la distancia al próximo lado en x y se avanza en la dirección x.
// si el lado y es más cercano, se actualiza la distancia al próximo lado en y y se avanza en la dirección y.
// después de avanzar, se verifica si la celda actual del mapa contiene una pared ('1').
// si es así, se marca que se ha golpeado una pared y el bucle termina.

// el resultado de este proceso es que se determina la celda del mapa donde el rayo golpea una pared
// y se registra qué lado de la pared fue golpeado (vertical u horizontal).


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
		if (game->config.map->grid[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
}
