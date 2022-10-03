SRCS_DIR	= ./src/
SRCS_FILES	=  main.c
SRCS_FILES	+= init_game.c mapLoading.c map_args.c map_errors.c maputils.c readmap.c ft_tab.c
SRCS_FILES	+= gameplay.c minimap.c mouse.c player_moves.c player_lateral_moves.c gun.c
SRCS_FILES	+= dda.c distances.c draw.c raycasting.c texturing.c texture_loading.c door.c
SRCS_FILES	+= ft_atoi.c ft_itoa.c ft_strlen.c get_next_line.c get_next_line_utils.c exit.c time.c

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

LIBFT		= ./libft
MAKELIB		= ${MAKE} -C ${LIBFT}

LIBX		= ./mlx

MAKELIBX	= @${MAKE} -C ${LIBX}


O_DIR		= ./objs/
HEADS		= -I./inc/ -I${LIBFT} -I${LIBX}

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

OBJS		+= ${LIBFT}/libft.a

OBJS		+= ${LIBX}/libmlx.a



LIBS		= -framework OpenGL -framework AppKit


NAME		= cub3D

CC			= cc
AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${O_DIR} ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} -fsanitize=address

${O_DIR}:
			${MKDIR} ${O_DIR}

${O_DIR}%.o:${SRCS_DIR}%.c | inc/cub3d.h
			${CC} ${CFLAGS} ${HEADS} -o $@ -c $<

${LIBFT}/libft.a:
			${MAKELIB} all

${LIBX}/libmlx.a:
			@${MAKELIBX} all

clean:
			${RM} ${OBJS} ${OBJSB}
			@${RM} -r ${O_DIR}
			@${MAKELIB} clean
			@${MAKELIBX} clean

fclean:		clean
			${RM} ${NAME}
			@${RM} -r ${NAME}.dSYM
			@${MAKELIB} fclean

re:			fclean all

.PHONY:		all clean fclean re debug
