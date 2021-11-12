#include "../headers/so_long.h"

void	initator_master(t_game *g)
{
	g->map.column = 0;
	g->map.line = 0;
	g->c_num = -1;
	g->e_num = -1;
	g->p_num = -1;
	g->map.map = NULL;
	g->mlx = NULL;
	g->mlx_win = NULL;
	init(&g->ugbcm);
}

void	ultimate_leave_in_bad_faith(t_game *g, int error_code)
{
	taking_out_trashes(&g->ugbcm);
	if (error_code == EE_NONE)
		printf("Everything has been close, see you !\n");
	if (error_code == EE_INVARG)
		printf("Error\n[->] Wrong number of arguments !\n");
	if (error_code == EE_INVMAP)
		printf("Error\n[->] Map is not buildable !\n");
	if (error_code == EE_INVMAL)
		printf("r44_boot fail to malloc\n[->] No worries I got out cleanly !\n");
	if (error_code == EE_INVNAM)
		printf("Error\n[->] Make an effort, map have to finish by .ber\n");
	printf("r44_boot never stamble\n");
	exit(0);
}

int		quit(t_game *ptr)
{
	if (ptr->mlx_win)
		mlx_destroy_window(ptr->mlx, ptr->mlx_win);
	if (ptr->mlx)
	{
		mlx_destroy_display(ptr->mlx);
		free(ptr->mlx);
	}
	ultimate_leave_in_bad_faith(ptr, EE_NONE);
	return (EXIT_SUCCESS);
}