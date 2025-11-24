/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:26:02 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/24 14:49:43 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "cub3d.h"

// ------------------------------------------------------
// 							UTILS
// ------------------------------------------------------

// FT_STRLEN.C
size_t	ft_strlen(char *s);

// ------------------------------------------------------
// 							CONFIG
// ------------------------------------------------------

// ERROR_HANDLER.C
int		error(char *msg);
int		error_sys(char *msg);

// FREE_SRC.C
void	free_img(t_game *game);
void	free_config(t_game *game);
int		free_game(t_game *game, int ret);

// INITTIAL_SETTINGS.C
void	init_img(t_img *img);
void	init_config(t_config *config);
void	init_player(t_player *player);
void	init_game(t_game *game);

// ------------------------------------------------------
// 							EVENTS
// ------------------------------------------------------

// CLOSING.C
int		game_exit(t_game *game, int status);
int		close_window(t_game *game);

// KEYS.C
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

// ------------------------------------------------------
// 							PARSING
// ------------------------------------------------------

// PARSE_FILE.C
int		parse_file(char *file, t_game *game);

// ------------------------------------------------------
// 							RENDERING
// ------------------------------------------------------

// RENDER.C
int		render_frame(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
#endif
