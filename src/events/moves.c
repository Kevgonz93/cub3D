#include "../../includes/src.h"

void	rotate_player(t_game *game)
{
	if (game->keys[KEY_LEFT])
	{
		game->config.player_angle -= ROT_SPEED;
		if (game->config.player_angle < 0)
			game->config.player_angle += 2 * PI;
	}
	if (game->keys[KEY_RIGHT])
	{
		game->config.player_angle += ROT_SPEED;
		if (game->config.player_angle >= 2 * PI)
			game->config.player_angle -= 2 * PI;
	}
}

static void	side_moves(t_game *game)
{
	if (game->keys[KEY_A])
	{
		game->player.x += cos(game->config.player_angle - PI / 2)
			* MOVE_SPEED;
		game->player.y += sin(game->config.player_angle - PI / 2)
			* MOVE_SPEED;
	}
	if (game->keys[KEY_D])
	{
		game->player.x += cos(game->config.player_angle + PI / 2)
			* MOVE_SPEED;
		game->player.y += sin(game->config.player_angle + PI / 2)
			* MOVE_SPEED;
	}
}

void	move_player(t_game *game)
{
	game->config.map->grid[(int)game->player.y][(int)game->player.x] = '0'; // QUITAR
	if (game->keys[KEY_W])
	{
		game->player.x += cos(game->config.player_angle) * MOVE_SPEED;
		game->player.y += sin(game->config.player_angle) * MOVE_SPEED;
	}
	if (game->keys[KEY_S])
	{
		game->player.x -= cos(game->config.player_angle) * MOVE_SPEED;
		game->player.y -= sin(game->config.player_angle) * MOVE_SPEED;
	}
	if (game->keys[KEY_A] || game->keys[KEY_D])
		side_moves(game);
	game->config.map->grid[(int)game->player.y][(int)game->player.x] = 'W'; // QUITAR
}

void	update_player(t_game *game)
{
	if (game->exit_status.confirm_exit)
		return ;
	if (game->keys[KEY_LEFT] || game->keys[KEY_RIGHT])
		rotate_player(game);
	if (game->keys[KEY_W] || game->keys[KEY_S] || game->keys[KEY_A]
		|| game->keys[KEY_D])
		move_player(game);
}
