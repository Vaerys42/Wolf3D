NAME =	Wolf3D

SRC =	src/ini.c \
		src/main.c \
		src/ray.c \
		src/print.c \
		src/move.c \
		src/error.c \
		src/map.c \
		src/save.c \
		src/check.c \
		src/minimap.c \

LIBS =	-framework OpenGL -framework Appkit minilibx_macos/libmlx.a libft/libft.a

OBJ =	$(patsubst src/%.c,obj/%.o,$(SRC))

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		make -C minilibx_macos/
		gcc $(LIBS) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	make -C libft/ clean
	/bin/rm -rf obj

fclean : clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean