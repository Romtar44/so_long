#include "../headers/so_long.h"

void	items_drawer(t_game *g)
{
	int		j;
	int		i;
	char	c;

	i = -1;
	c = 0;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			c = g->map.map[i][j];
			if (c == 'C')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->tex[ETI_ITEM].img, j * 64, i * 64);
		}
	}
}

void	map_drawer(t_game *g)
{
	int		j;
	int		i;
	char	c;

	i = -1;
	c = 0;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			c = g->map.map[i][j];
			if (c == '0' || c == 'P')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->tex[ETI_GROUND].img, j * 64, i * 64);
			else if (c == '1')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->tex[ETI_WALL].img, j * 64, i * 64);
			else if (c == 'E')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->tex[ETI_EXIT].img, j * 64, i * 64);
		}
	}
}
int	dasher_master(t_game *g, int dash, int *index, int status)
{
	if (status == 0)
		g->l_dash = 0;
	else if (status == 1)
		g->r_dash = 0;
	else
	{
		g->player.x += dash;
		g->r_dash = 0;
		g->l_dash = 0;
		g->player.moved = 1;
		*index = 0;
		check_items(g);
	}
	return (1);
}
		
int	ultimate_dasher_master(t_game *g)
{
	static int	i = 0;

	if (g->player.view_point == EV_RIGHT)
	{
		if (g->player.x + DASH_SIZE >= g->map.column)
			return (dasher_master(g, DASH_SIZE, &i, EV_RIGHT));
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->dash.tex[1].img, g->player.x * 64, g->player.y * 64);
		if (i == FRAMERATE / 2)
			dasher_master(g, DASH_SIZE, &i, 2);
	}	
	else if (g->player.view_point == EV_LEFT)
	{
		if (g->player.x - DASH_SIZE < 1)
			return (dasher_master(g, -DASH_SIZE, &i, EV_LEFT));
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->dash.tex[0].img, g->player.x * 64, g->player.y * 64);
		if (i == FRAMERATE / 2)
			dasher_master(g, -DASH_SIZE, &i, 2);
	}
	++i;
	return (i);
}

int	ft_sqrt(int nb)
{
        unsigned int i;

        i = 1;
        if (nb < 1)
                return (i);
        while (i * i < (unsigned int)nb)
                i++;
        return ((i * i == (unsigned int)nb) ? i : i);
}

int	ft_pow(int nb, int power)
{
        int i;
        int r;

        i = 0;
        r = nb;
        if (power < 0)
                return (0);
        if (power == 0)
                return (1);
        while (i < power - 1)
        {
                r *= nb;
                i++;
        }
        return (r);
}

int	monster_range(t_game *g, t_player *mob)
{
	int	a;
	int	dist;
	
	a = ft_pow(mob->x - g->player.x, 2) + ft_pow(mob->y - g->player.y, 2);
	dist = ft_sqrt(a);
	if (dist < V_RANGE)
		return (dist);
	else
		return (0);
}

void	monster_move(t_game *g, t_player *mob)
{
	int	x;
	int	y;

	x = mob->x;
	y =mob->y;
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->tex[ETI_GROUND].img, x * 64, y * 64);
	if (x < g->player.x)
		player_move_right(g, mob);
	else if (x > g->player.x)
		player_move_left(g, mob);
	else
	{
		if (y < g->player.y)
			player_move_backward(g, mob);
		else if (y > g->player.y)
			player_move_forward(g, mob);
	}
}

void	monster_attack_master(t_game *g, t_player *mob)
{
	static int	i = 0;
	static int	j = 0;

	g->player.health -= DAMAGE;
	if (mob->view_point == EV_RIGHT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[j + 2].img, mob->x * 64, mob->y * 64);
	else
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[j + 9].img, mob->x * 64, mob->y * 64);
	if (i == FRAMERATE)
	{
		++j;
		if (j == 3)
		{
			j = 0;
			mob->attack_stand = 0;
		}	
		i = 0;
	}
	else
		++i;
}

void	monster_attacked_master(t_game *g, t_player *mob)
{
	static int	i = 0;

	mob->health = 0;
	if (mob->status < 1)
	{
		if (i < E_FRAMERATE / 2 && mob->view_point == EV_LEFT)
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME6].img, mob->x * 64, mob->y * 64);
		else if (i < E_FRAMERATE && i >= E_FRAMERATE / 2 && mob->view_point == EV_LEFT)
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME7].img, mob->x * 64, mob->y * 64);
		else if (i < E_FRAMERATE / 2 && mob->view_point == EV_RIGHT)
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME13].img, mob->x * 64, mob->y * 64);
		else if (i < E_FRAMERATE && i >= E_FRAMERATE / 2 && mob->view_point == EV_RIGHT)
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME14].img, mob->x * 64, mob->y * 64);
	}
	if (i == E_FRAMERATE)
	{
		i = 0;
		++mob->status;
	}
	++i;
}

void	play_monster(t_game *g, int index)
{
	static int	i = 0;
	int			pos;

	pos = monster_range(g, &g->monster[index]);
	if (i < E_FRAMERATE / 2 && g->monster[index].view_point == EV_LEFT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME1].img, g->monster[index].x * 64, g->monster[index].y * 64);
	else if (i < E_FRAMERATE && i >= E_FRAMERATE / 2 && g->monster[index].view_point == EV_LEFT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME2].img, g->monster[index].x * 64, g->monster[index].y * 64);
	else if (i < E_FRAMERATE / 2 && g->monster[index].view_point == EV_RIGHT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME8].img, g->monster[index].x * 64, g->monster[index].y * 64);
	else if (i < E_FRAMERATE && i >= E_FRAMERATE / 2 && g->monster[index].view_point == EV_RIGHT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->enemy.tex[EAI_FRAME9].img, g->monster[index].x * 64, g->monster[index].y * 64);
	if (pos > 1)
	{
		if (i == E_FRAMERATE)
			monster_move(g, &g->monster[index]);
	}	
	else if (pos == 1)
		g->monster[index].attack_stand = 1;
	++i;
	if (i > E_FRAMERATE)
		i = 0;
}

int	ultimate_loop_hook(t_game *g)
{
	static int	i = 0;
	static int	j = 0;
	int			e;

	e = -1;
	while (++e < ENEMY_NUMBER)
	{
		if (g->monster[e].health)
		{
			play_monster(g, e);
			if (g->monster[e].attack_stand == 1)
				monster_attack_master(g, &g->monster[e]);
		}
		else if (!g->monster[e].health)
			if (g->monster[e].status < 1)
				monster_attacked_master(g, &g->monster[e]);
	}
	if (g->player.moved == 1)
	{
		map_drawer(g);
		items_drawer(g);
		g->player.moved = 0;
	}
	if (g->r_dash || g->l_dash)
	{
		ultimate_dasher_master(g);
		return (0);
	}
	if (g->player.view_point == EV_RIGHT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->stand.tex[j].img, g->player.x * 64, g->player.y * 64);
	else
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->stand.tex[j + 4].img, g->player.x * 64, g->player.y * 64);
	if (i == FRAMERATE)
	{
		++j;
		i = 0;
		if (j >= 4)
			j = 0;
	}
	else
		++i;
	return (0);
}
