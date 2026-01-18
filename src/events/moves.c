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

static int	is_walkable_cell(t_game *game, int mx, int my)
{
	int		len;
	char	c;

	if (my < 0 || my >= game->config.map->height)
		return (0);
	len = (int)ft_strlen(game->config.map->grid[my]);
	if (mx < 0 || mx >= len)
		return (0);
	c = game->config.map->grid[my][mx];
	if (c == '1' || c == ' ')
		return (0);
	return (1);
}

static int	can_move_to(t_game *game, float x, float y)
{
	float	r;

	r = (float)PLAYER_RADIUS;
	if (!is_walkable_cell(game, (int)((x + r) / TILE_SIZE),
		(int)(y / TILE_SIZE)))
		return (0);
	if (!is_walkable_cell(game, (int)((x - r) / TILE_SIZE),
		(int)(y / TILE_SIZE)))
		return (0);
	if (!is_walkable_cell(game, (int)(x / TILE_SIZE),
		(int)((y + r) / TILE_SIZE)))
		return (0);
	if (!is_walkable_cell(game, (int)(x / TILE_SIZE),
		(int)((y - r) / TILE_SIZE)))
		return (0);
	return (1);
}

static void	make_move(t_game *game, float dx, float dy)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (can_move_to(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move_to(game, game->player.x, new_y))
		game->player.y = new_y;
}

static void	add_forback_moves(t_game *game, float *dx, float *dy)
{
	float	angle;

	angle = game->config.player_angle;
	if (game->keys[KEY_W])
	{
		*dx += cos(angle) * MOVE_SPEED;
		*dy += sin(angle) * MOVE_SPEED;
	}
	if (game->keys[KEY_S])
	{
		*dx -= cos(angle) * MOVE_SPEED;
		*dy -= sin(angle) * MOVE_SPEED;
	}
}

static void	add_side_moves(t_game *game, float *dx, float *dy)
{
	float	angle;

	angle = game->config.player_angle;
	if (game->keys[KEY_A])
	{
		*dx += cos(angle - (PI / 2)) * MOVE_SPEED;
		*dy += sin(angle - (PI / 2)) * MOVE_SPEED;
	}
	if (game->keys[KEY_D])
	{
		*dx += cos(angle + (PI / 2)) * MOVE_SPEED;
		*dy += sin(angle + (PI / 2)) * MOVE_SPEED;
	}
}

void	move_player(t_game *game)
{
	float	dx;
	float	dy;

	dx = 0.0f;
	dy = 0.0f;
	printf("pos=(%.2f,%.2f) cell=(%d,%d)\n",
		game->player.x, game->player.y,
		(int)(game->player.x / TILE_SIZE),
		(int)(game->player.y / TILE_SIZE));
	add_forback_moves(game, &dx, &dy);
	add_side_moves(game, &dx, &dy);
	if (dx != 0.0f || dy != 0.0f)
		make_move(game, dx, dy);
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
