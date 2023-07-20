NAME = minishell

LIB_DIR = libft
SRC_DIR = ./src
VPATH = src:libft

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj

INCLUDES = -Ilibft -Iinc
CFLAGS = -Wall -Wextra -Werror -MMD -g

SRC = main.c error_exit.c env.c\
signals.c linked_lst_utils.c parser.c\
check_input.c tokenization.c tokenization_utils1.c\
check_input2.c parsing_utils1.c linked_lst_utils2.c\

DEP = $(OBJ:.o=.d)

##

all: $(NAME)

$(NAME):  $(OBJ)
		make -C $(LIB_DIR)
		cc $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP)

clean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
