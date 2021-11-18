#include "../headers/so_long.h"

int	m_i_ber(char *str)
{
	int		i;
	int		j;
	char	*comp;

	i = 0;
	j = 0;
	comp = ".ber";
	while (str[i])
		++i;
	if (i < 4)
		return (0);
	i -= 5;
	while (str[++i])
		if (str[i] != comp[j++])
			return (0);
	return (1);
}

size_t	map_size(int fd, t_game *g)
{
	size_t	bytes;
	int		stop;
	char	c;

	stop = 1;
	bytes = 0;
	while (stop)
	{
		stop = read(fd, &c, 1);
		if (stop > 0)
			++bytes;
		else if (stop == -1)
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
	}
	return (bytes);
}

size_t	n_ny_n(char *str)
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (str[++i])
		if (str[i] == '\n' && str[i + 1] != 0)
			++ret;
	return (ret);
}

size_t	many_n(char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret])
	{
		if (ret == 0 && str[ret] == '\n')
			return (0);
		if (str[ret] == '\n')
			break ;
		++ret;
	}
	return (ret);
}
char	*give_me_my_line(char *ret, char *tmp_map, int index, t_game *g)
{
	int	i;

	i = 0;
	if (!tmp_map)
	{
		*ret = 0;
		return (NULL);
	}
	while (tmp_map[i] != '\n' && tmp_map[i])
	{
		if ((index == 0 || index == g->map.line - 1) && tmp_map[i] != '1')
			ultimate_leave_in_bad_faith(g, EE_INVMAP);
		ret[i] = tmp_map[i];
		++i;
	}
	ret[i] = 0;
	if (tmp_map[i] == '\n')
		++i;
	if (tmp_map[i] == '\0')
		return (NULL);
	return (tmp_map + i);
}
