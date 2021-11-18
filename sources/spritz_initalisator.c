#include "../headers/so_long.h"

void	image_initialisator(t_game *g, char *path, enum e_texture_indexes idx)
{
	t_spritz	*tmp;

	tmp = NULL;
	tmp = &g->tex[idx];
	tmp->img = mlx_xpm_file_to_image(g->mlx, path, &tmp->width, &tmp->height);
	if (!tmp->img)
		ultimate_leave_in_bad_faith(g, EE_INVIMG);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->size_line, &tmp->endian);
	if (!tmp->addr)
		ultimate_leave_in_bad_faith(g, EE_INVIMG);
}

void	anim_initialisator(t_game *g, char *path, t_anim *anim, enum e_anim_indexes idx)
{
	t_spritz	*tmp;

	tmp = NULL;
	tmp = &anim->tex[idx];
	tmp->img = mlx_xpm_file_to_image(g->mlx, path, &tmp->width, &tmp->height);
	if (!tmp->img)
		ultimate_leave_in_bad_faith(g, EE_INVIMG);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->size_line, &tmp->endian);
	if (!tmp->addr)
		ultimate_leave_in_bad_faith(g, EE_INVIMG);
}

void	spritz_drinker(t_game *g)
{
	g->stand.size = 8;
	anim_initialisator(g, "data/player/player/stand1.xpm", &g->stand, EAI_FRAME1);
	anim_initialisator(g, "data/player/player/stand2.xpm", &g->stand, EAI_FRAME2);
	anim_initialisator(g, "data/player/player/stand3.xpm", &g->stand, EAI_FRAME3);
	anim_initialisator(g, "data/player/player/stand4.xpm", &g->stand, EAI_FRAME4);
	anim_initialisator(g, "data/player/player/fstand1.xpm", &g->stand, EAI_FRAME5);
	anim_initialisator(g, "data/player/player/fstand2.xpm", &g->stand, EAI_FRAME6);
	anim_initialisator(g, "data/player/player/fstand3.xpm", &g->stand, EAI_FRAME7);
	anim_initialisator(g, "data/player/player/fstand4.xpm", &g->stand, EAI_FRAME8);
	g->dash.size = 2;
	anim_initialisator(g, "data/player/player/ldash.xpm", &g->dash, EAI_FRAME1);
	anim_initialisator(g, "data/player/player/rdash.xpm", &g->dash, EAI_FRAME2);

}

void	spritz_abuser(t_game *g)
{
	(void)g;
	g->enemy.size = 14;
	anim_initialisator(g, "data/player/enemy/stand1.xpm", &g->enemy, EAI_FRAME1);
	anim_initialisator(g, "data/player/enemy/stand2.xpm", &g->enemy, EAI_FRAME2);
	anim_initialisator(g, "data/player/enemy/attack1.xpm", &g->enemy, EAI_FRAME3);
	anim_initialisator(g, "data/player/enemy/attack2.xpm", &g->enemy, EAI_FRAME4);
	anim_initialisator(g, "data/player/enemy/attack3.xpm", &g->enemy, EAI_FRAME5);
	anim_initialisator(g, "data/player/enemy/dead1.xpm", &g->enemy, EAI_FRAME6);
	anim_initialisator(g, "data/player/enemy/dead2.xpm", &g->enemy, EAI_FRAME7);
	anim_initialisator(g, "data/player/enemy/fstand1.xpm", &g->enemy, EAI_FRAME8);
	anim_initialisator(g, "data/player/enemy/fstand2.xpm", &g->enemy, EAI_FRAME9);
	anim_initialisator(g, "data/player/enemy/fattack1.xpm", &g->enemy, EAI_FRAME10);
	anim_initialisator(g, "data/player/enemy/fattack2.xpm", &g->enemy, EAI_FRAME11);
	anim_initialisator(g, "data/player/enemy/fattack3.xpm", &g->enemy, EAI_FRAME12);
	anim_initialisator(g, "data/player/enemy/fdead1.xpm", &g->enemy, EAI_FRAME13);
	anim_initialisator(g, "data/player/enemy/fdead2.xpm", &g->enemy, EAI_FRAME14);
}

void	spritz_mastor(t_game *g)
{
	image_initialisator(g, "data/env/end_bricks.xpm", ETI_GROUND);
	image_initialisator(g, "data/env/dragon_egg.xpm", ETI_WALL);
	image_initialisator(g, "data/env/New-Piskel.xpm", ETI_ITEM);
	image_initialisator(g, "data/env/chest.xpm", ETI_EXIT);
	spritz_drinker(g);
	spritz_abuser(g);
}