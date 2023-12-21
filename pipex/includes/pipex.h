/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:00:43 by fsantos2          #+#    #+#             */
/*   Updated: 2023/12/20 21:56:06 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_all
{
	int				pid;
	int				pip[2];
	int				dups[2];
	char			*cmd;
	char			**cmd_av;
	char			*file;
	int				hd_fd;
	char			*hd_delim;
	struct s_all	*next;
	struct s_all	*prev;
}					t_all;

char				*ft_strdup_path(char *env, int *x, char *cmd);
void				start_pipex(t_all *all, char **env);
char				*path(t_all *all, char *env, char *cmd);
char				*search_path(char **env, char *cmd);
int					ft_strlen_path(char *env, int x);
void				free_everything(t_all *all);
void				execute_path(t_all *all, char **env);
void				execute_infile(t_all *cmd);
void				execute_to_outfile(t_all *cmd);
void				execute_heredoc(t_all *cmd);
int					ft_strlen_cmd(char *cmd);
char				*ft_join(char *str, char *delim, char *cmd);
void				return_path(char **env, t_all *all);
void				free_array(char **str);
void				handle_std(t_all *cmd);
void				check_files(char *file, t_all *all);
void				free_list(t_all *all);
void				execute(t_all *cmd, char **env);
void				check_hd(t_all *tmp, t_all *all);
void				number_args(t_all *all);

#endif