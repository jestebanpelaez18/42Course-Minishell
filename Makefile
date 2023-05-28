# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 10:44:41 by jpelaez-          #+#    #+#              #
#    Updated: 2023/05/28 10:47:27 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = 

OBJECT = $(SRC:.c=.o)

HEADER = .h

FLAGS = -Wall -Wextra -Werror 
IFLAGS = -I $(HEADER) 

CC = CC 

all: $(NAME) 

$(NAME):  $(OBJECT) 
		$(CC) $(FLAGS) $(IFLAGS) $(OBJECT) -o $(NAME) 

	
clean:
	rm -f $(OBJECT) 

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean