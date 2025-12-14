/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:14:41 by kegonza           #+#    #+#             */
/*   Updated: 2025/12/14 12:57:32 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>

# include "mlx.h"

// ------------------------------------------------------
//                     CONSTANTES
// ------------------------------------------------------
// Dimensiones de la ventana
# define WIDTH  1000
# define HEIGHT 700
# define TILE 10 // PARA DEBUGEAR, QUITAR LUEGO

// Variables matemáticas
# define PI		3.14159265358979323846

// Teclas (MacOS por defecto)
# define KEY_W        13
# define KEY_A        0
# define KEY_S        1
# define KEY_D        2
# define KEY_LEFT     123
# define KEY_RIGHT    124
# define KEY_ESC      53

// ------------------------------------------------------
//                     ESTRUCTURAS
// ------------------------------------------------------

typedef struct s_dda
{
	double	ray_dir_x;		// Dirección del rayo X
	double	ray_dir_y;		// Dirección del rayo Y
	int		map_x;			// Posición del mapa X
	int		map_y;			// Posición del mapa Y
	double	side_dist_x;	// Distancia al siguiente lado X
	double	side_dist_y;	// Distancia al siguiente lado Y
	double	delta_dist_x;	// Distancia entre lados X
	double	delta_dist_y;	// Distancia entre lados Y
	int		step_x;			// Paso en X
	int		step_y;			// Paso en Y
	int		hit;			// ¿Se ha golpeado una pared?
	int		side;			// ¿Se ha golpeado una pared vertical u horizontal?
}	t_dda;

// Imagen generada con mlx_new_image
typedef struct s_img
{
	void	*img;			// Puntero a la imagen
	char	*addr;			// Puntero a los datos de la imagen
	int		bpp;			// Bits por píxel
	int		line_len;		// Longitud de una línea en bytes
	int		endian;			// Endianness
}	t_img;

// Información del jugador
typedef struct s_player
{
	double	x;				// Posición X
	double	y;				// Posición Y
	double	dir_x;			// Dirección X
	double	dir_y;			// Dirección Y
	double	plane_x;		// Plano de la cámara X
	double	plane_y;		// Plano de la cámara Y
}	t_player;

// Mapa en matriz
typedef struct s_map
{
	char	**grid;			// Matriz del mapa
	int		width;			// Ancho del mapa
	int		height;			// Alto del mapa
}	t_map;

// Configuración del archivo .cub
typedef struct s_config
{
	char				*no_tex;		// Textura norte
	char				*so_tex;		// Textura sur
	char				*we_tex;		// Textura oeste
	char				*ea_tex;		// Textura este
	unsigned int		floor_color;	// Color del suelo
	unsigned int		ceil_color;		// Color del techo
	double				fov;			// Campo de visión
	double				player_angle;	// Ángulo inicial del jugador
	t_map				*map;
}	t_config;

// Estructura principal del juego
typedef struct s_game
{
	void		*mlx;		// Puntero a la instancia de MLX
	void		*win;		// Puntero a la ventana
	t_img		img;		// Imagen para renderizar
	t_config	config;		// Configuración del juego
	t_player	player;		// Información del jugador
	int			keys[256];	// Estado de las teclas
}	t_game;

#endif
