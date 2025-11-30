NAME    := cub3D

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3 # QUITAR -g3

OS      := $(shell uname)

# ==========================
# MiniLibX per-OS selection
# ==========================

ifeq ($(OS), Darwin)
	MLX_DIR   := minilibx/macos
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	X11_FLAGS :=
else
	MLX_DIR   := minilibx/linux
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd
	X11_FLAGS :=
endif

INCLUDES := -I$(MLX_DIR) -Iinclude

SRCS := $(wildcard src/*.c) \
        $(wildcard src/utils/*.c) \
        $(wildcard src/rendering/*.c) \
        $(wildcard src/parsing/*.c) \
        $(wildcard src/events/*.c) \
		$(wildcard src/config/*.c) \
		$(wildcard debug/*.c) \
        $(wildcard *.c)

OBJS := $(SRCS:.c=.o)

RM   := rm -f

# ==========================
# Rules
# ==========================

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(X11_FLAGS) $(MLX_FLAGS) -o $(NAME)
	## vv ELIMINAR ANTES DE ENTREGAR vv
	make clean

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	-$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
