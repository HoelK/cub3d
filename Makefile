CC=cc
FLAGS=-Wall -Wextra -Werror -g3
SRCS=srcs/main.c \
	 srcs/error.c \
	 srcs/arg_check.c \
	 srcs/display_management.c \
	 srcs/cub_interpreter/data.c \
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
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./$(LIBFT_DIR) -lft -L./minilibx-linux/ -lmlx -lXext -lX11 -lm -lz
	@echo "\e[1;32m [CUB3D] Build Complete !\e[1;30"
	

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "\e[1;32m [CUB3D] Compiling $^\e[1;30"
	@$(CC) $(FLAGS) -c $^ -o $@ -I./headers/

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
