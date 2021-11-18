#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> //remove

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>

# include "../minilibx-linux/mlx.h"

# include "sl_definitions.h"
# include "sl_structures.h"
# include "../Ultimate-Garbage-Collector-Master/ugbcm.h"

					/* initialisation and leaving */
void	ultimate_leave_in_bad_faith(t_game *g, int error_code);
int		quit(t_game *ptr);
void	initator_master(t_game *g);

					/* map checker */
void	parser_mapper_master(t_game *g, char *mapp);
char	**ultimate_parser_master(t_game *g, char *tmp_map);
char	**ultimate_parser(t_game *g, char *tmp_map, char **ret);
void	map_format_checker(t_game *g);
void	valid_display(t_game *g, char display);

					/* map checker utils */					
int		m_i_ber(char *str);
size_t	map_size(int fd, t_game *g);
size_t	n_ny_n(char *str);
size_t	many_n(char *str);
char	*give_me_my_line(char *ret, char *tmp_map, int index, t_game *g);

					/* map drawing */
void	map_drawer(t_game *g);
int		ultimate_loop_hook(t_game *g);
void	items_drawer(t_game *g);

				/* movement functions */
void	player_dash(t_game *g);
void	player_move_forward(t_game *g, t_player *ent);
void	player_move_backward(t_game *g, t_player *ent);
void	player_move_left(t_game *g, t_player *ent);
void	player_move_right(t_game *g, t_player *ent);

				/* sprites initialisation */
void	image_initialisator(t_game *g, char *path, enum e_texture_indexes idx);
void	anim_initialisator(t_game *g, char *path, t_anim *anim, enum e_anim_indexes idx);
void	spritz_drinker(t_game *g);
void	spritz_mastor(t_game *g);

void	check_items(t_game *g);

void	monster_attacked_master(t_game *g, t_player *mob);

#endif
