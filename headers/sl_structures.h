#ifndef SL_STRUCTURES_H
# define SL_STRUCTURES_H

# include "so_long.h"
# include "../Ultimate-Garbage-Collector-Master/ugbcm.h"



typedef struct s_player
{
	int	x;
	int	y;
	int	view_point;
	int	moved;
	int	status;
	int	health;
	int	attack_stand;
}	t_player;

typedef struct s_map
{
	int		line;
	int		column;
	char	**map;
}	t_map;

typedef	struct s_spritz
{
	int		width;
	int		height;
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}	t_spritz;

typedef struct s_anim
{
	size_t		size;
	t_spritz	tex[15];
}	t_anim;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			c_num;
	int			p_num;
	int			e_num;
	int			r_dash;
	int			l_dash;
	t_ugbcm		ugbcm;
	t_map		map;
	t_spritz	tex[5];
	t_player	player;
	t_player	monster[ENEMY_NUMBER];
	t_anim		stand;
	t_anim		dash;
	t_anim		enemy;
}	t_game;

#endif
