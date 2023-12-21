/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:32:01 by fsantos2          #+#    #+#             */
/*   Updated: 2023/12/20 20:16:33 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	free_everything(t_all *all)
{
	t_all	*tmp;
	t_all	*curr;

	curr = all;
	while (all->prev)
		all = all->prev;
	while (all)
	{
		free_array(all->cmd_av);
		if (all == curr)
			free(all->cmd);
		tmp = all;
		all = all->next;
		free(tmp);
	}
}

void	free_list(t_all *all)
{
	t_all	*tmp;

	while (all)
	{
		tmp = all;
		all = all->next;
		free(tmp);
	}
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
