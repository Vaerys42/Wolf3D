NAME =	Wolf3D

SRC =	ini.c \
		main.c \
		ray.c \
		print.c \
		move.c \
		error.c \

LIBS =	-framework OpenGL -framework Appkit minilibx_macos/libmlx.a libft/libft.a

OBJ =	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
		make -C minilibx_macos/
		gcc -c -g $(SRC)
		gcc $(LIBS) $(OBJ) -o $(NAME)

clean :
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean