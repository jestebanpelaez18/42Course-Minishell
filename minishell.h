/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:41:26 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/30 12:36:24 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**env;
	int		exit_status;
	char	*line_read;
	char	**tokens;
	char	*token;

}			t_data;

void		error_msg(char *msg);

/*Signal functions*/
void		signal_in_exec(void);
void		start_signal(void);

/* Enviroment functions */
char		**envdup(char **env);

/*Lexer Utils*/
int			check_line(t_data *data, char *line);

/*Tokenization*/
void		tokenization(t_data *data);
int			count_tokens(char *line, char *del);
int 		check_delimiter(char c, char *delimiter);
#endif
