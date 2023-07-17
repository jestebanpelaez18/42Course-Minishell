#include "minishell.h"

static	int	nb_argv(char **argv)
{
	int		size;

	size = 0;
	while (argv[size])
		size++;
	return (size);
}

int	ft_echo(char **argv)
{
	int		i;
	int		n_option;

	i = 1;
	n_option = 0;  // check "-n" new line option in echo
	if (nb_argv(argv) > 1)
	{
		while (argv[i] && ft_strcmp(argv[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (argv[i])
		{
			ft_putstr_fd(argv[i], 1);
			if (argv[i + 1] && argv[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (0);
}
