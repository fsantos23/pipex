/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:42:56 by fsantos2          #+#    #+#             */
/*   Updated: 2023/12/20 21:54:59 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_files(char *file, t_all *all)
{
	if (access(file, F_OK) != 0)
	{
		ft_printf("no such file: %s\n", file);
		free_list(all);
		exit(0);
	}
}

void	check_hd(t_all *tmp, t_all *all)
{
	if (!tmp->prev)
		return ;
	ft_printf("not valid arguments\n");
	free_list(all);
}

void	execute_path(t_all *cmd, char **env)
{
	if (pipe(cmd->pip) < 0)
		return ;
	cmd->pid = fork();
	if (cmd->pid < 0)
		return ;
	if (cmd->pid != 0)
	{
		if (cmd->prev)
			close(cmd->prev->pip[0]);
		close(cmd->pip[1]);
		if (!cmd->next)
			close(cmd->pip[0]);
		cmd->cmd = NULL;
	}
	else
		execute(cmd, env);
}

void	number_args(t_all *all)
{
	int		a;
	t_all	*tmp;

	a = 0;
	tmp = all;
	while (tmp)
	{
		if (tmp->cmd)
			a++;
		tmp = tmp->next;
	}
	if (a <= 1)
	{
		printf("not enough commands\n");
		free_list(all);
		exit(0);
	}
}
