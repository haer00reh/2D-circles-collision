#Compiler
CC = cc

#Compilation flags
CFLAGS = -Wall -Wextra -Werror -I includes `sdl2-config --cflags`

#Linker flags
LDFLAGS = `sdl2-config --libs` -lm
# add_circle.c  draw_all_circles.c  free_circles.c  handle_collisions.c  main.c  pull_toward_cursor.c  redraw_circles.c

#Sources
SRCS = srcs/main.c \
	srcs/add_circle.c \
	srcs/redraw_circles.c \
	srcs/draw_all_circles.c \
	srcs/free_circles.c \
	srcs/handle_collisions.c \
	srcs/pull_toward_cursor.c
#.o files
OBJS = $(SRCS:.c=.o)
#x name
NAME = collisions
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
