CC=cc
FLAGS=-Wall -Wextra -Werror -g3
SRCS=srcs/main.c \
	 srcs/dda.c \
	 srcs/init.c \
	 srcs/kill.c \
	 srcs/draw.c \
	 srcs/mouse.c \
	 srcs/error.c \
	 srcs/utils.c \
	 srcs/points.c \
	 srcs/raycast.c \
	 srcs/sprite.c \
	 srcs/minimap.c \
	 srcs/renderer.c \
	 srcs/crosshair.c \
	 srcs/movements.c \
	 srcs/arg_check.c \
	 srcs/key_events.c \
	 srcs/dda_getters.c \
	 srcs/display_management.c \
	 srcs/cub_interpreter/data.c \
	 srcs/cub_interpreter/doors.c \
	 srcs/cub_interpreter/dumper.c \
	 srcs/cub_interpreter/color_handle.c \
	 srcs/cub_interpreter/id_handle.c \
	 srcs/cub_interpreter/link_handle.c \
	 srcs/cub_interpreter/map_handle.c \
	 srcs/cub_interpreter/map_checker.c \
	 srcs/cub_interpreter/error_management.c
LIBFT=libft.a
LIBFT_DIR=libft/
OBJS=$(SRCS:.c=.o)
NAME=cub3d

.PHONY: all start $(NAME) $(LIBFT)

all: start $(NAME)

start:
	@echo "\e[1;33m===============CUB3D===============\e[1;30"

$(NAME): $(OBJS) $(LIBFT)
	@echo "\e[1;33m===============CUB3D===============\e[1;30"
	@echo "\e[1;32m [CUB3D] Building library...\e[1;30"
	@$(CC) $(FLAGS) $(OBJS) -L./$(LIBFT_DIR) -lft -lmlx_Linux -L./minilibx-linux/ -lXext -lX11 -lm -o $(NAME)
	@echo "\e[1;32m [CUB3D] Build Complete !\e[1;30"
	

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "\e[1;32m [CUB3D] Compiling $^\e[1;30"
	@$(CC) $(FLAGS) -c $^ -o $@ -I./headers/ -I./minilibx-linux/

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
