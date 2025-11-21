NAME := cub3D

CC := cc
CFLAGS := -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

# ==========================
# MiniLibX per-OS selection
# ==========================
ifeq ($(UNAME_S),Linux)
    # ---- Linux: uses X11 ----
    MLX_DIR := ./minilibx-linux
    MLX_LIB := $(MLX_DIR)/libmlx.a
    MLX_INC := -I$(MLX_DIR)
    MLX_LFLAGS := -lm -lXext -lX11
else
    # ---- macOS: uses frameworks ----
    MLX_DIR := ./minilibx
    MLX_LIB := $(MLX_DIR)/libmlx.a
    MLX_INC := -I$(MLX_DIR)
    MLX_LFLAGS := -framework OpenGL -framework AppKit
endif

INCLUDES := -Iinclude $(MLX_INC)

SRCS := $(wildcard src/*.c) \
		$(wildcard src/utils/*.c) \
		$(wildcard src/rendering/*.c) \
		$(wildcard src/parsing/*.c) \
		$(wildcard src/events/*.c) \
		main.c
OBJS := $(SRCS:.c=.o)

RM := rm -f

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_LIB) $(MLX_LFLAGS) -o $(NAME)

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
