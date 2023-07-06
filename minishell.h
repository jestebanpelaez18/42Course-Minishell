/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:41:26 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/07/06 17:56:29 by jpelaez-         ###   ########.fr       */
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

typedef struct s_token
{
	char			*toke;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_data
{
	char			**env;
	int				exit_status;
	char			*line_read;
	char			**tokens;

}					t_data;

/*Input checker*/
void				error_msg(char *msg);
void				error_msg_noexit(char *msg);

/*Signal functions*/
void				signal_in_exec(void);
void				start_signal(void);

/* Enviroment functions */
char				**envdup(char **env);

/*Lexer Utils*/
int					check_line(t_data *data, char *line);

/*Tokenization*/
void				tokenization(t_data *data);
int					count_tokens(char *line, char *del);
int 				is_whitespace(char *line, int i);

#endif
