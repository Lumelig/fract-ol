NAME = fractol

SRCS = main.c window.c init.c render.c

OBJECTS = $(SRCS:%.c=%.o)
HEADER = fractol.h

MLX_DIR = mlx
MLX_REPO = https://github.com/codam-coding-college/MLX42.git

# New library example (libft)
LIBFT_DIR = libft
LIBFT_REPO = https://github.com/Lumelig/libft.git

MLX = $(MLX_DIR)/build/libmlx42.a
LIBFT = $(LIBFT_DIR)/libft.a

# Combine library paths and link flags
LIBS = -ldl -lglfw -pthread -lm
LIB_DIRS = -L$(MLX_DIR)/build -L$(LIBFT_DIR)
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)/includes

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code

all: mlx libft ${NAME}

mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@cmake ./mlx/ -B $(MLX_DIR)/build
	@make -C $(MLX_DIR)/build -j4

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

${NAME}: $(OBJECTS) mlx libft
	${CC} ${CFLAGS} -o ${NAME} $(OBJECTS) $(MLX) $(LIBFT) $(LIBS) $(LIB_DIRS) $(INCLUDES)

clean:
	rm -f $(OBJECTS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR)/build clean

fclean: clean
	rm -f ${NAME}
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re mlx libft