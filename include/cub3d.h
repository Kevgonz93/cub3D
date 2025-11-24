/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:14:41 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/24 14:16:26 by kegonza          ###   ########.fr       */
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

# include "mlx.h"
# include "src.h"

// ------------------------------------------------------
//                     CONSTANTES
// ------------------------------------------------------
# define WIDTH  1000
# define HEIGHT 700

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
	char	*no_tex;		// Textura norte
	char	*so_tex;		// Textura sur
	char	*we_tex;		// Textura oeste
	char	*ea_tex;		// Textura este
	int		floor_color;	// Color del suelo
	int		ceil_color;		// Color del techo
	t_map	*map;
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

// ------------------------------------------------------
//                 PROTOTIPOS (mínimos)
// ------------------------------------------------------

// INITIAL_SETTINGS.C
void	init_game(t_game *game);


// FREE_SRC.C
void	free_img(t_game *game);
void	free_config(t_game *game);
int		free_game(t_game *game, int exit_code);

// ERROR_HANDLER.C
int		error(char *msg);
int		error_sys(char *msg);

// MAIN.C
int		parse_file(char *path, t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		game_exit(t_game *game, int status);
int		close_window(t_game *game);
int		render_frame(t_game *game);


#endif
