/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:34:20 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/12 18:34:50 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <errno.h>

static char	*find_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	split_path(struct s_dat *data, char **envp)
{
	char	*path;

	path = find_path(envp);
	data->path_split = ft_split(path, ':');
	if (!data->path_split)
		cleanup(data, 1, "ft_split");
}

bool	check_if_path(struct s_dat *data, char *program)
{
	if (ft_strchr(program, '/'))
	{
		data->program_path = ft_strdup(program);
		if (!data->program_path)
			cleanup(data, 1, NULL);
		return (true);
	}
	return (false);
}

void	get_program_path(struct s_dat *data, char *program)
{
	size_t	i;
	int		status;

	i = 0;
	status = 0;
	while (data->path_split[i])
	{
		data->program_path = ft_pathjoin(data->path_split[i], program);
		if (!data->program_path)
			cleanup(data, 1, "ft_pathjoin");
		if (access(data->program_path, F_OK) == 0)
		{
			if (access(data->program_path, X_OK) == 0)
				return ;
			else
				status = errno;
		}
		free(data->program_path);
		data->program_path = NULL;
		i++;
	}
	if (status)
		errno = status;
	cleanup(data, 1, program);
}

void	get_program_av(struct s_dat *data, char *arg)
{
	data->program_av = ft_split(arg, ' ');
	if (!data->program_av)
		cleanup(data, 1, "ft_split");
}
