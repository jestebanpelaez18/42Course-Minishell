/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:41:26 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/17 18:50:21 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

# define WORD 0
# define PIPE 1
# define LEFT_R 2
# define RIGH_R 3
# define HEREDOC 4
# define APPEND 5

typedef struct s_token
{
	char			*tokens;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_cmd
{
	char			**commands;
	t_token			*tok_struct;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_data
{
	char			**env;
	int				exit_status;
	int				pipex;
	t_cmd			*struc_cmd;
	char			*line_read;
	char			**tokens;
	t_token			*struc_tok;
}					t_data;

/*Error msg*/
void				error_msg(char *msg);
void				error_msg_noexit(char *msg);

/*Signal functions*/
void				signal_in_exec(void);
void				start_signal(void);

/* Enviroment functions */
char				**envdup(char **env);

/*Check input*/
int					check_line(t_data *data, char *line);
int					syntax_redirection(char *line);

/*Tokenization*/
void				tokenization(t_data *data);
int					count_tokens(char *line, char *del);
int					is_whitespace(char *line, int i);
int					check_token_type(char c);
int					tok_closed_quotes(char *str, int i, char quote);
int					operator_type(char operator);
int					check_delimiter(char c, char *delimiter);

/*Parser*/

void				parser(t_data *data);
void				set_number_of_pipes(t_data *data, t_token *tokens);
int					count_commands(t_token *node);

/*Linked list utils*/

void				ft_lstadd_back(t_token **lst, t_token *new);
t_token				*ft_lstlast(t_token *lst);
t_token				*ft_lstnew(char *token, int type);
t_cmd				*cmd_new(char **token);
t_cmd				*cmd_last(t_cmd *lst);
void				cmd_add_back(t_cmd **lst, t_cmd *new);
int					create_cmd_node(char **sub_line, t_cmd **commands);

void				printList(t_token *node);

#endif
