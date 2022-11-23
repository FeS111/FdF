MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

VPATH = src

# Compiler Variables
CC		 = cc
# CFLAGSS	 = -Wall -Wextra -Werror -g
INCFLAG	 = -I src -I libft
MLXFLAGS = MLX42/libmlx42.a -lglfw -L /Users/$(USER)/homebrew/opt/glfw/lib/ -framework Cocoa -framework OpenGL -framework IOKit
# MLXFLAGS = MLX42/libmlx42_arm.a -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/ -framework Cocoa -framework OpenGL -framework IOKit
AR		 = ar
ARFLAGS  = -rcs
# File Variables
NAME	 = fdf
SRC		 = $(addprefix src/, main.c map.c ft_util.c ft_draw.c ft_init.c ft_project.c color.c)
OBJ		 = $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) | libft/libft.a
	$(CC) -o $(NAME) $(CFLAGSS) $(INCFLAG) $(OBJ) libft/libft.a $(MLXFLAGS)

libft/libft.a: libft
	(cd libft && make && make clean)

libft:
	@if [ ! -d "libft" ]; then git clone https://github.com/fes111/libft.git; fi

_bin :
	mkdir _bin

_bin/%.o : %.c libft/libft.a | _bin
	$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

san: CFLAGSS += -fsanitize=address

san: re

run: $(NAME)
	- ./$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	(cd libft && make fclean)

re:		fclean all

all:	$(NAME)

.PHONY: clean fclean re all run