/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:14:41 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/23 17:24:52 by akwadran         ###   ########.fr       */
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

# include "../minilibx/mlx.h"
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
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// Información del jugador
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

// Mapa en matriz
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

// Configuración del archivo .cub
typedef struct s_config
{
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		floor_color;
	int		ceil_color;
	t_map	*map;
}	t_config;

// Estructura principal del juego
typedef struct s_game
{
	void		*mlx;
	void		*win;

	t_img		img;
	t_config	config;
	t_player	player;

	int			keys[256];
}	t_game;

// ------------------------------------------------------
//                 PROTOTIPOS (mínimos)
// ------------------------------------------------------

// INITIAL_SETTINGS.C
void	init_game(t_game *game);

int		parse_file(char *path, t_game *game);

// FREE_SRC.C
void	free_img(t_game *game);
void	free_config(t_game *game);
int		free_game(t_game *game, int exit_code);

// ERROR_HANDLER.C
int		error(char *msg);
int		error_sys(char *msg);


// eventos
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_window(t_game *game);

// dibujo / render loop
int		render_frame(t_game *game);


#endif
