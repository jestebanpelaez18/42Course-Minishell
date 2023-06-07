# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 10:44:41 by jpelaez-          #+#    #+#              #
#    Updated: 2023/06/07 16:30:53 by junheeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c error_exit.c env.c\
signals.c\

OBJECT = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = minishell.h

FLAGS = -Wall -Wextra -Werror
C_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
O_FLAGS = -I${HOME}/.brew/opt/readline/include
CC = CC

all: $(NAME)

$(NAME):  $(OBJECT)
		make -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(C_FLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(O_FLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJECT)

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
