#include "../headers/so_long.h"

int	printkey(int keycode)
{
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_game	g;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, 120, 120, "so_long by r44_root");
	mlx_key_hook(g.mlx_win, printkey, &g);
	mlx_loop(g.mlx);
	return (0);
}