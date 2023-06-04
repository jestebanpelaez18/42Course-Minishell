# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 10:44:41 by jpelaez-          #+#    #+#              #
#    Updated: 2023/06/01 20:14:09 by jpelaez-         ###   ########.fr        #
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
IFLAGS = -I $(HEADER) 
RLNFLAG = -lreadline 

CC = CC 

all: $(NAME) 

$(NAME):  $(OBJECT) 
		make -C $(LIBFT_DIR)
		$(CC) $(RLNFLAG) $(FLAGS) $(IFLAGS) $(OBJECT) $(LIBFT) -o $(NAME) 

	
clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJECT) 

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean