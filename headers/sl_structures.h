#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

# include "so_long.h"
# include "../Ultimate-Garbage-Collector-Master/ugbcm.h"

typedef struct s_map
{
	int		line;
	int		column;
	char	**map;
}	t_map;


typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		c_num;
	int		p_num;
	int		e_num;
	t_map	map;
	t_ugbcm	ugbcm;
}	t_game;

#endif
