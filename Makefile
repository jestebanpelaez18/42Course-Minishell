# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 10:44:41 by jpelaez-          #+#    #+#              #
#    Updated: 2023/07/13 18:50:49 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c error_exit.c env.c\
signals.c linked_lst_utils.c\
check_input.c tokenization.c tokenization_utils1.c parser.c\
check_input2.c parsing_utils1.c\

OBJECT = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = minishell.h

FLAGS = -Wall -Wextra -Werror
C_FLAGS = -lreadline -L ${HOME}/.brew/opt/readline/lib
O_FLAGS = -I ${HOME}/.brew/opt/readline/include
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
