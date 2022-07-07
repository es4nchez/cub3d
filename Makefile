SRC	=	src/main.c src/map_errors.c src/mapLoading.c src/gameplay.c src/raycasting.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cub3d

RM	=	rm -f
CC	=	clang
CFLAGS	=	-Wall -Werror -Wextra
OPTIONS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(OPTIONS) $(OBJ) -g -o $(NAME)

all	:	$(NAME)


clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
