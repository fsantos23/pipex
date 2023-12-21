/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:02 by fsantos2          #+#    #+#             */
/*   Updated: 2023/12/21 13:23:48 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	execute(t_all *cmd, char **env)
{
	handle_std(cmd);
	close(cmd->pip[0]);
	close(cmd->pip[1]);
	if (cmd->prev)
		close(cmd->prev->pip[0]);
	cmd->cmd_av = ft_split(cmd->cmd, ' ');
	cmd->cmd = search_path(env, cmd->cmd_av[0]);
	if (!cmd->cmd)
	{
		close(cmd->dups[0]);
		close(cmd->dups[1]);
		ft_printf("pois pois nao existes\n");
		free_everything(cmd);
		exit(1);
	}
	execve(cmd->cmd, cmd->cmd_av, env);
	free_everything(cmd);
	close(cmd->dups[0]);
	close(cmd->dups[1]);
	perror("execve");
	exit(1);
}

void	handle_std(t_all *cmd)
{
	if (!cmd->prev)
		execute_infile(cmd);
	else if (!cmd->next)
		execute_to_outfile(cmd);
	else
	{
		cmd->dups[0] = dup2(cmd->prev->pip[0], STDIN_FILENO);
		cmd->dups[1] = dup2(cmd->pip[1], STDOUT_FILENO);
	}
}

void	execute_infile(t_all *cmd)
{
	int	fd_file;

	fd_file = open(cmd->file, O_RDONLY);
	if (fd_file < 0)
		exit(1);
	cmd->dups[0] = dup2(fd_file, STDIN_FILENO);
	close(fd_file);
	cmd->dups[1] = dup2(cmd->pip[1], STDOUT_FILENO);
}

void	execute_to_outfile(t_all *cmd)
{
	int	fd_file;

	fd_file = open(cmd->file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd_file < 0)
		exit(1);
	cmd->dups[0] = dup2(cmd->prev->pip[0], STDIN_FILENO);
	cmd->dups[1] = dup2(fd_file, STDOUT_FILENO);
	close(fd_file);
}
