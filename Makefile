NAME = minishell

LIB_DIR = libft
SRC_DIR = ./src
VPATH = src:libft

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj

INCLUDES = -Ilibft -Iinc

FLAGS = -Wall -Wextra -Werror -MMD -g

# MAC_OS
O_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
C_FLAGS = -I${HOME}/.brew/opt/readline/include

# LINUX
# Uncomment these lines if you are building for Linux instead of macOS
#O_FLAGS = -lreadline
#C_FLAGS =

SRC = main.c error_exit.c env.c \
signals.c linked_lst_utils.c parser.c \
check_input.c tokenization.c tokenization_utils1.c \
check_input2.c parsing_utils1.c linked_lst_utils2.c \
linked_lst_utils3.c parse_redic.c expander.c expander_utils1.c \
expander_utils2.c expander_utils3.c

DEP = $(OBJ:.o=.d)

##

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	cc $(FLAGS) $(C_FLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft $(O_FLAGS)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(FLAGS) $(INCLUDES) $(C_FLAGS) -c $< -o $@

-include $(DEP)

clean:
	make -C $(LIB_DIR) fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean