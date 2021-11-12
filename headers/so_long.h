#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> //remove

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

# include "../minilibx-linux/mlx.h"

# include "sl_definitions.h"
# include "sl_structures.h"
#include "../Ultimate-Garbage-Collector-Master/ugbcm.h"

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
size_t	map_size(int fd);
size_t	n_ny_n(char *str);
size_t	many_n(char *str);
char	*give_me_my_line(char *ret, char *tmp_map, int index, t_game *g);

#endif
