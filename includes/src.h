/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:26:02 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/30 17:45:42 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "cub3d.h"

// ------------------------------------------------------
// 							UTILS
// ------------------------------------------------------

// FT_STRLEN.C
size_t	ft_strlen(const char *s);
// FT_STRDUP.C
char	*ft_strdup(const char *s);
// FT_STRJOIN.C
char	*ft_strjoin(char *s1, const char *s2);
// FT_SUBSTR.C
char	*ft_substr(char const *s, unsigned int start, size_t len);
// FT_STRLCPY.C
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// GET_NEXT_LINE.C
char	*get_next_line(int fd);
// FREE_ARRAY.C
void	free_array(char **array);
// FT_STRCMP.C
int	ft_strcmp(const char *s1, const char *s2);
// FT_ISSPACE.C
int	ft_isspace(int c);
// FT_SPLIT.C
char	**ft_split(char const *s, char c);
// FT_ISDIGIT.C
int	ft_isdigit(int c);
// FT_ATOI.C
int	ft_atoi(const char *nptr);

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

// BUFFER.C
char	**get_lines(char *file);

// TEXTURES.C
int	get_tex(char *line, t_game *game);
int	get_color(char *line, t_game *game);

// ------------------------------------------------------
// 							RENDERING
// ------------------------------------------------------

// RENDER.C
int		render_frame(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color);

// ------------------------------------------------------
// 							DEBUG
// ------------------------------------------------------

void	print_config(t_config *config);
void    print_array(char **array);

#endif
