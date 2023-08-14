/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:19:32 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/08/09 18:38:29 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_redirection(t_redirec *input)
{
	int	fd;

	fd = open(input->token, O_RDONLY);
	if (fd == -1)
		error_msg("Failed to open file");
	if (fd > 0 && dup2(fd, STDIN_FILENO) == -1)
		error_msg("Failed in dup2");
	close(fd);
}

void	output_redirection(t_redirec *input)
{
	int	fd;

	if (input->type == RIGH_R)
		fd = open(input->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(input->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		error_msg("Failed to open file");
	if (fd > 0 && dup2(fd, STDIN_FILENO) == -1)
		error_msg("Failed in dup2");
	close(fd);
}

/*We just check the kind of redirections that we have in our program,
	and then we open
the file descriptors for every case*/

void	setup_redirections(t_redirec *redirections)
{
	t_redirec	*temp;

	temp = redirections;
	while (temp)
	{
		if (temp->type == LEFT_R || temp->type == HEREDOC)
			output_redirection(temp);
		else if (redirections->type == RIGH_R || redirections->type == RIGH_R)
			input_redirection(temp);
		temp = temp->next;
	}
	return ;
}