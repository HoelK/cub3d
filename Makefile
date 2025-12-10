CC=cc
FLAGS=-Wall -Wextra -Werror -g -O3
SRCS=main.c \
	 parse.c
LIBFT=libft.a
LIBFT_DIR=libft/
OBJS=$(SRCS:.c=.o)
NAME=cub3d

.PHONY: all start $(NAME) $(LIBFT)

start:
	@echo "\e[1;33m===============CUB3D===============\e[1;30"

all: start $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\e[1;32m [CUB3D] Building library...\e[1;30"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./$(LIBFT_DIR) -lft
	@echo "\e[1;32m [CUB3D] Build Complete !\e[1;30"
	

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "\e[1;32m [CUB3D] Compiling $^\e[1;30"
	@$(CC) $(FLAGS) -c $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
