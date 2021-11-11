NAME	:= so_long

FILES	:= so_long.c
SOURCES	:= $(addprefix sources/,$(FILES))
OBJECTS	:= $(SOURCES:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	 = -MMD -MF $(@:.o=.d)

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
