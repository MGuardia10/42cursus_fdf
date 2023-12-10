# NAME
NAME = fdf

# LIBRARIES AND FRAMEWORKS
LIBFT			= libft/libft.a
MLX				= mlx/libmlx.a #= -Lmlx -lmlx
FRAMEWORKS		= -framework OpenGL -framework AppKit
# -Lmlx -lmlx -> La opción -Lmlx especifica dónde encontrar la biblioteca
# y -lmlx especifica la biblioteca en sí que debe ser enlazada.

# SOURCE FILES
SRC_DIR			=	src/
SRC_FILES		= 	main.c \
					parsing.c \
					draw.c \
					draw_utils.c \
					draw_menu_1.c \
					draw_menu_2.c \
					colors.c \
					key_press_controls.c \
					key_press.c \
					mouse_press.c \
					mouse_move.c \
					mouse_release.c \
					utils.c \
					exit.c
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_DIR			= objs/
OBJ_FILES 		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g -O3
INCLUDE = -I includes
RM		= rm -rf

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
	@echo "\n$(BLUE)Compiling libft and MinilibX.$(CLEAR)"
	@make -sC libft
	@echo "$(GREEN)[libft --> OK]$(CLEAR)"
	@make -sC mlx
	@echo "$(GREEN)[MiniLibX --> OK]\n$(CLEAR)"
	@echo "$(BLUE)Compiling the FDF program.$(CLEAR)"
	$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $(MLX) $(FRAMEWORKS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)[fdf --> OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"
	@echo "$(PINK)\tUsage: ./fdf <path_map>$(CLEAR)\n"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)Removing compiled files.$(CLEAR)"
	@make clean -sC libft
	@make clean -sC mlx
	$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC libft
	@make fclean -sC mlx
	@echo "$(BLUE)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)
	@echo "$(GREEN)Object files and binary removed correctly\n$(CLEAR)"

re: fclean all

.PHONY:		all clean fclean re