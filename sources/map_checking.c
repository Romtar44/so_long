#include "../headers/so_long.h"

char	**ultimate_parser(t_game *g, char *tmp_map, char **ret)
{
	int		i;
	int		sz;

	sz = 0;
	i = -1;
	g->map.column = many_n(tmp_map);
	while (++i < g->map.line)
	{
		if (tmp_map)
			sz = many_n(tmp_map);
		if (sz != g->map.column)
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
		ret[i] = better_than_malloc(&g->ugbcm, sz + 1, sizeof(char));
		if (!ret[i])
			ultimate_leave_in_bad_faith(g, EE_INVMAL);
		tmp_map = give_me_my_line(ret[i], tmp_map, i, g);
	}
	return (ret);
}

char	**ultimate_parser_master(t_game *g, char *tmp_map)
{
	char	**ret;

	ret = NULL;
	g->map.line = n_ny_n(tmp_map);
	if (g->map.line < 3)
		ultimate_leave_in_bad_faith(g, EE_INVMAP);
	ret = better_than_malloc(&g->ugbcm, g->map.line + 1, sizeof(char *));
	if (!ret)
		ultimate_leave_in_bad_faith(g, EE_INVMAL);
	ret[g->map.line] = 0;
	ret = ultimate_parser(g, tmp_map, ret);
	return (ret);
}

void	valid_display(t_game *g, char c)
{
	if (c == 'P')
	{
		if (g->p_num == -1)
			g->p_num = 1;
		else
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
	}
	else if (c == 'C')
	{
		if (g->c_num == -1)
			g->c_num = 1;
		else
			++g->c_num;
	}
	else if (c == 'E')
	{
		if (g->e_num == -1)
			g->e_num = 1;
		else
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
	}
	else if (c == '0' || c == '1')
		return ;
	else
		ultimate_leave_in_bad_faith(g, EE_INVMAP);
}

void	map_format_checker(t_game *g)
{
	int	i;
	int	j;

	i = 1;
	while (i < g->map.line - 1)
	{
		j = 0;
		if (g->map.map[i][j] != '1')
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
		while (g->map.map[i][j])
		{
			if (g->map.map[i][j] == 'P')
			{
				g->player.x = j;
				g->player.y = i;
			}
			valid_display(g, g->map.map[i][j]);
			++j;
		}
		if (g->map.map[i][j - 1] != '1')
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
		i++;
	}
	if (g->c_num <= 0 || g->e_num <= 0 || g->p_num != 1)
		ultimate_leave_in_bad_faith(g, EE_INVMAP);
}

void	parser_mapper_master(t_game *g, char *mapp)
{
	int		fd;
	size_t	size;
	char	*tmp_map;

	tmp_map = NULL;
	if (!m_i_ber(mapp))
		ultimate_leave_in_bad_faith(g, EE_INVNAM);
	fd = open(mapp, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0)
		ultimate_leave_in_bad_faith(g, EE_INVMAP);
	size = map_size(fd, g);
	close(fd);
	tmp_map = better_than_malloc(&g->ugbcm, size + 1, sizeof(char));
	if (! tmp_map)
		ultimate_leave_in_bad_faith(g, EE_INVMAL);
	fd = open(mapp, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0)
		ultimate_leave_in_bad_faith(g, EE_INVMAP);
	read(fd, tmp_map, size);
	close(fd);
	tmp_map[size] = 0;
	g->map.map = ultimate_parser_master(g, tmp_map);
	map_format_checker(g);
}