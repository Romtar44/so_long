#include "../headers/so_long.h"

int	key_hk(int keycode, t_game *g)
{
	if (keycode == EK_ESC)
		quit(g);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	g;

	initator_master(&g);
	if (ac != 2)
		ultimate_leave_in_bad_faith(&g, EE_INVARG);
	parser_mapper_master(&g, av[1]);
	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, 1280, 720, "so_long by r44_root");
	mlx_hook(g.mlx_win, DestroyNotify, NoEventMask, quit, &g);
	mlx_key_hook(g.mlx_win, key_hk, &g);
	mlx_loop(g.mlx);
	return (EXIT_SUCCESS);
}