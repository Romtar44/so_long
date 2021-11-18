#include "../headers/so_long.h"

void	player_dash(t_game *g)
{
	int	x;
	int	y;

	x = g->player.x;
	y = g->player.y;
	if (g->player.view_point == EV_LEFT)
	{
		if (g->map.map[y][x - DASH_SIZE] != '1')
		{
			g->player.moved = 1;
			g->l_dash = 1;
		}
	}
	else
	{
		if (g->map.map[y][x + DASH_SIZE] != '1')
		{
			g->player.moved = 1;
			g->r_dash = 1;
		}
	}
}

void	player_move_forward(t_game *g, t_player *ent)
{
	int	x;
	int	y;

	x = ent->x;
	y = ent->y;
	if (g->map.map[y - 1][x] != '1')
	{
		ent->moved = 1;
		--ent->y;
	}
}

void	player_move_backward(t_game *g, t_player *ent)
{
	int	x;
	int	y;

	x = ent->x;
	y = ent->y;
	if (g->map.map[y + 1][x] != '1')
	{
		ent->moved = 1;
		++ent->y;
	}
}

void	player_move_left(t_game *g, t_player *ent)
{
	int	x;
	int	y;

	x = ent->x;
	y = ent->y;
	ent->view_point = EV_LEFT;
	if (g->map.map[y][x - 1] != '1')
	{
		ent->moved = 1;
		--ent->x;
	}
}

void	player_move_right(t_game *g, t_player *ent)
{
	int	x;
	int	y;

	x = ent->x;
	y = ent->y;
	ent->view_point = EV_RIGHT;
	if (g->map.map[y][x + 1] != '1')
	{
		ent->moved = 1;
		++ent->x;
	}
}