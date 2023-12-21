/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:10:17 by fsantos2          #+#    #+#             */
/*   Updated: 2023/12/21 13:02:44 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	start_pipex(t_all *all, char **env)
{
	t_all	*tmp;

	tmp = all;
	number_args(all);
	while (tmp)
	{
		if (tmp->file != NULL && !tmp->prev)
			check_files(tmp->file, all);
		execute_path(tmp, env);
		tmp = tmp->next;
	}
	tmp = all;
	while (tmp)
	{
		waitpid(tmp->pid, NULL, 0);
		tmp = tmp->next;
	}
	free_everything(all);
}

char	*check_cmd(char *cmd)
{
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	**search_env(char **env)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 6) != NULL)
		{
			path = ft_substr(env[i], 6, ft_strlen(env[i]));
			break ;
		}
		i++;
	}
	if (!path)
		perror("env search error\n");
	else
	{
		paths = ft_split(path, ':');
		free(path);
	}
	return (paths);
}

char	*search_path(char **env, char *cmd)
{
	char	**paths;
	char	*part;
	int		i;

	i = 0;
	paths = NULL;
	if (ft_strchr(cmd, '/') != NULL)
		return (check_cmd(cmd));
	paths = search_env(env);
	while (paths[i])
	{
		part = ft_join(paths[i], "/", cmd);
		if (access(part, F_OK) == 0)
		{
			free_array(paths);
			return (part);
		}
		free(part);
		i++;
	}
	free_array(paths);
	return (NULL);
}

char	*ft_join(char *str, char *delim, char *cmd)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(str, delim);
	new = ft_strjoin(tmp, cmd);
	free(tmp);
	return (new);
}
