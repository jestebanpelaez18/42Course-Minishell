/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:17:38 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/24 15:56:57 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_heredoc(char *line, t_data *data)
{
	char	*str;

	if (is_dollar(line))
	{
		str = replace_dollar(line, data);
		free(line);
	}
	else
	{
		str = ft_strdup(line);
		free(line);
	}
	return (str);
}

int	read_input(t_redirec *redic, int fd, t_data *data)
{
	char	*line;

	line = readline(">");
	if (!line)
		return (1);
	while (line && ft_strncmp(redic->token, line, ft_strlen(redic->token)) != 0
		&& g_var.heredoc_signal == 0)
	{
		line = expand_heredoc(line, data);
		ft_putendl_fd(line, fd);
		free(line);
		if (g_var.heredoc_signal == 1)
			break ;
		line = readline(">");
	}
	if (line)
		free(line);
	return (g_var.heredoc_signal);
}

int	heredoc(t_redirec *redirec, t_data *data)
{
	int	temp_fd;
	int	line_s;

	line_s = 0;
	temp_fd = open(redirec->hd_file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (temp_fd < 0)
	{
		ft_putendl_fd("Failed open fd", 2);
		return (1);
	}
	heredoc_signal();
	line_s = read_input(redirec, temp_fd, data);
	close(temp_fd);
	return (line_s);
}

char	*heredoc_name(int n_file)
{
	char	*number;
	char	*temp;

	number = ft_itoa(n_file);
	temp = ft_strjoin("hd_temp", number);
	free(number);
	return (temp);
}

void	setup_heredoc(t_data *data, t_redirec *redirections)
{
	t_redirec	*temp;
	int			line_status;
	int			n_file;

	temp = redirections;
	line_status = 0;
	n_file = 0;
	while (temp)
	{
		if (temp->type == HEREDOC)
		{
			// if (temp->hd_file_name)
			// 	free(temp->hd_file_name);
			temp->hd_file_name = heredoc_name(n_file);
			line_status = heredoc(temp, data);
			if (line_status)
			{
				g_var.g_exit_status = 1;
				return ;
			}
			n_file++;
		}
		temp = temp->next;
	}
}
