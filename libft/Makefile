# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:54:41 by jpelaez-          #+#    #+#              #
#    Updated: 2023/08/24 20:09:59 by rrask            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoinfree.c\

SRCB =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
ft_lstlast.c ft_lstadd_back.c\

HEADER = -c -Ilibft

FLAGS = -Wall -Wextra -Werror

OBJECT = ${SRC:.c=.o}

OBJECTB =	ft_lstnew.o ft_lstadd_front.o ft_lstsize.o\
ft_lstlast.o ft_lstadd_back.o\

all: $(NAME)

$(NAME):
	cc -c $(FLAGS) $(SRC) $(HEADER) 
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME) 
	
bonus:
	cc -c $(FLAGS) $(SRCB) $(HEADER) 
	ar rc $(NAME) $(OBJECTB)
	ranlib $(NAME) 
	
clean:
	rm -f $(OBJECT) $(OBJECTB)

fclean: clean
	   rm -f $(NAME)

re: fclean all