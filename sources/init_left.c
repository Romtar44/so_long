#include "../headers/so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

void	initator_master(t_game *g)
{
	ft_memset(g, 0, sizeof(t_game));
	g->map.column = 0;
	g->map.line = 0;
	g->c_num = -1;
	g->e_num = -1;
	g->p_num = -1;
	g->player.moved = 1;
	g->player.health = P_HP;
	g->player.view_point = EV_RIGHT;
	init(&g->ugbcm);
}

void print_error_message(int error_code)
{
	if (error_code == EE_NONE)
		printf("Everything has been closed, see you !\n");
	if (error_code == EE_GG)
		printf("I hope you enjoy the game <3\nEverything has been closed, see you !\n");
	if (error_code == EE_INVARG)
		printf("Error\n[->] Wrong number of arguments !\n");
	if (error_code == EE_INVMAP)
		printf("Error\n[->] Map is not buildable !\n");
	if (error_code == EE_INVMAL)
		printf("r44_boot fail to malloc\n[->] No worries I got out cleanly !\n");
	if (error_code == EE_INVNAM)
		printf("Error\n[->] Make an effort, map have to finish by .ber\n");
	if (error_code == EE_INVIMG)
		printf("Error\n[->] Nice try, but img creations failed !\n Obviously, everything has been closed, see you !\n");
	printf("r44_boot never stamble\n");
}
void	ultimate_image_destroyer(t_game *g, t_spritz *free, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (free[i].img)
			mlx_destroy_image(g->mlx, free[i].img);
}

void	ultimate_leave_in_bad_faith(t_game *g, int error_code)
{
	ultimate_image_destroyer(g, g->tex, 4);
	ultimate_image_destroyer(g, g->dash.tex, g->dash.size);
	ultimate_image_destroyer(g, g->enemy.tex, g->enemy.size);
	ultimate_image_destroyer(g, g->stand.tex, g->stand.size);
	if (g->mlx_win)
		mlx_destroy_window(g->mlx, g->mlx_win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	taking_out_trashes(&g->ugbcm);
	print_error_message(error_code);
	exit(0);
}

int		quit(t_game *g)
{
	ultimate_leave_in_bad_faith(g, EE_NONE);
	return (EXIT_SUCCESS);
}
