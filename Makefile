# NAME
NAME = fdf

# LIBFT
LIBFT = libft/libft.a

# SOURCE FILES
SRC_DIR			=	src/
SRC_FILES		= 	main.c \
					parse_args.c \
					key_press.c \
					key_release.c \
					mouse_press.c \
					mouse_release.c \
					mouse_move.c \
					draw.c \
					draw_menu.c \
					utils.c
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_FILES 		= $(SRC:.c=.o)

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
INCLUDE = -I includes
RM		= rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	@make -sC libft
	@make -sC mlx
	@echo "$(PINK)Compiling the FDF program.$(CLEAR)"
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ_FILES) $(INCLUDE) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c -o $@ $<

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	@make clean -sC libft
	$(RM) $(OBJ_FILES)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC libft
	@make clean -sC mlx
	@echo "$(PINK)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all clean fclean re