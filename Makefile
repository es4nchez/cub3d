# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 12:23:24 by yalthaus          #+#    #+#              #
#    Updated: 2022/07/22 14:16:17 by yalthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Exec Name
NAME	= cub3d

# Compilation
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
HEADS		= -I$(INC) -I${LIBFTDIR}
OPTION		= -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

# SRC
SRCDIR 		= ./src/
INC			= ./inc/
LIBFTDIR	= ./libft/
BUILDDIR	= ./build/
LIBFT		= $(addprefix $(LIBFTDIR), libft.a)
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRCS		= $(addprefix $(SRCDIR), $(SRCNAMES))

# command + OBJ
RM		= rm -rf
MKDIR	= mkdir -p
MAKE	= make --no-print-directory -C
OBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]

# Action

all: $(NAME)

$(BUILDDIR):
			@mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
			@echo "[..] $(NAME)... compiling $*.c\r\c"
			@$(CC) $(CFLAGS) $(HEADS) -o $@ -c $<
			@echo "$(_CLEAR)"

$(LIBFT):
			@$(MAKE) $(LIBFTDIR) all bonus

$(NAME): $(BUILDDIR) $(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(OPTION) -o $@ $(OBJS) $(LIBFT) $(LIBS)
			@echo "$(_OK) $(NAME) compiled"
clean:
			@rm -rf $(BUILDDIR)
			@$(MAKE) $(LIBFTDIR) clean

fclean: clean
			@$(MAKE) $(LIBFTDIR) fclean
			@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all fclean clean re
