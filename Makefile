NAME = fractol

SRCS = main.c

OBJECTS = $(SRCS:%.c=%.o)

MLX_DIR = mlx

MLX_REPO = https://github.com/codam-coding-college/MLX42.git

MLX 		=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast -ffast-math -march=native -mtune=native -funroll-loops

INC =  

CC = cc

CFLAGS			= -Wall -Werror -Wextra -Wunreachable-code -Ofast -ffast-math -march=native -mtune=native -funroll-loops #-lm

all: mlx ${NAME}

${NAME}: $(OBJECTS)
	${CC} ${CFLAGS} -o ${NAME} $(OBJECTS) libmlx42.a -ldl -lglfw -pthread -lm

mlx:
	if [ ! -d "$(MLX_DIR)" ]; then git clone $(MLX_REPO) $(MLX_DIR); fi
	cmake ./mlx/ -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4 CFLAGS+="-Ofast -ffast-math -march=native -mtune=native -funroll-loops"
	mv mlx/build/libmlx42.a ./