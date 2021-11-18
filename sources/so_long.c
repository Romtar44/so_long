#include "../headers/so_long.h"

void	check_items(t_game *g)
{
	int	x;
	int	y;

	x = g->player.x;
	y = g->player.y;
	if (g->map.map[y][x] == 'C')
	{
		--g->c_num;
		g->map.map[y][x] = '0';
	}
	if (g->map.map[y][x] == 'E')
		if (g->c_num == 0)
			ultimate_leave_in_bad_faith(g, EE_GG);
}

int	key_hk(int keycode, t_game *g)
{
	if (keycode == EK_ESC)
		quit(g);
	else if (keycode == EK_Z)
		player_move_forward(g, &g->player);
	else if (keycode == EK_S)
		player_move_backward(g, &g->player);
	else if (keycode == EK_Q)
		player_move_left(g, &g->player);
	else if (keycode == EK_D)
		player_move_right(g, &g->player);
	else if (keycode == EK_E)
		player_dash(g);
	else if (keycode == EK_A)
		monster_attacked_master(g, &g->monster[0]);
	check_items(g);
	return (keycode);
}

int	main(int ac, char **av)
{
	t_game	g;

	initator_master(&g);
	if (ac != 2)
		ultimate_leave_in_bad_faith(&g, EE_INVARG);
	parser_mapper_master(&g, av[1]);
	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, (g.map.column * 64), (g.map.line * 64), "so_long by r44_root");
	spritz_mastor(&g);

	g.monster[0].health = 25;
	g.monster[1].health = 25;
	g.monster[0].x = 5;
	g.monster[0].y = 5;
	g.monster[1].x = 10;
	g.monster[1].y = 8;

	mlx_hook(g.mlx_win, DestroyNotify, NoEventMask, quit, &g);
	mlx_key_hook(g.mlx_win, key_hk, &g);
	mlx_loop_hook(g.mlx, &ultimate_loop_hook, &g);
	mlx_loop(g.mlx);
	return (EXIT_SUCCESS);
}