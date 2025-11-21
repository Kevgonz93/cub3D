NAME := cub3D

CC := cc
CFLAGS := -Wall -Wextra -Werror

OS = $(shell uname)

# ==========================
# MiniLibX per-OS selection
# ==========================

ifeq ($(OS), Darwin)
	MLX_DIR   = minilibx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	X11_FLAGS = -I/opt/X11/include -L/opt/X11/lib -lX11 -lXext
else
	MLX_DIR   = minilibx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd
	X11_FLAGS =
endif

SRCS := $(wildcard src/*.c) \
		$(wildcard src/utils/*.c) \
		$(wildcard src/rendering/*.c) \
		$(wildcard src/parsing/*.c) \
		$(wildcard src/events/*.c) \
		$(wildcard *.c)
OBJS := $(SRCS:.c=.o)

RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(X11_FLAGS) $(MLX_FLAGS) -o $(NAME)
## vv ELIMINAR ANTES DE ENTREGAR vv
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean || true

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
