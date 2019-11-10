NAME = fdf
LIBFT = $(addprefix libft/, libft.a)

OPTIONS = -I. -Ilibft/includes

SRC = main.c \
		read_map.c \
		init.c \

FLS = -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o:%.c
		gcc $(OPTIONS) $(FLS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	gcc $(FLS) $(OBJ)  -o $(NAME) $(OPTIONS) -L libft  -lft -lmlx -framework OpenGL -framework AppKit

run : $(NAME)
	./$(NAME)

clean:
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all