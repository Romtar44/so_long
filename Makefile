NAME	:= so_long

FILES	:= init_left.c  map_checking.c  map_checking_utils.c  so_long.c
FUGBCM	:= ugbcm_utils.c  ugbcm.c
SOURCES	:= $(addprefix sources/,$(FILES)) $(addprefix Ultimate-Garbage-Collector-Master/,$(FUGBCM))
OBJECTS	:= $(SOURCES:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-linux -c $< -o $@

clean:
	make -C minilibx-linux clean
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
