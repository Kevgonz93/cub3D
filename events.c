#include "include/cub3d.h"

int		key_press(int keycode, t_game *game)
{
    (void)keycode;
    (void)game;
    return (0);
}

int		close_window(t_game *game)
{
    (void)game;
    mlx_loop_end(game->mlx);
    return (0);
}

int		key_release(int keycode, t_game *game)
{
    (void)keycode;
    (void)game;
    return (0);
}

int		render_frame(t_game *game)
{
    (void)game;
    return (0);
}
