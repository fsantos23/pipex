/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:03:23 by fsantos2          #+#    #+#             */
/*   Updated: 2023/12/21 13:02:33 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

t_all	*check_something(t_all *cmd, t_all *head, char **argv, int *i)
{
	if (!cmd)
		exit(1);
	if (ft_strncmp(argv[*i], "here_doc", 9) == 0)
	{
		cmd->hd_fd = *i;
		cmd->hd_delim = argv[++(*i)];
		(*i)++;
	}
	else if (!head)
		cmd->file = argv[(*i)++];
	cmd->cmd = argv[(*i)++];
	return (cmd);
}

void	create_list(int argc, char **argv, char **env)
{
	t_all	*head;
	t_all	*cmd;
	t_all	*tmp;
	int		i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		cmd = ft_calloc(1, sizeof(t_all));
		cmd = check_something(cmd, head, argv, &i);
		if (i == argc - 1)
			cmd->file = argv[(i)++];
		if (!head)
			head = cmd;
		else
		{
			tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = cmd;
			cmd->prev = tmp;
		}
	}
	start_pipex(head, env);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 4)
	{
		ft_printf("not enough arguments\n");
		return (0);
	}
	else
		create_list(argc, argv, env);
}
