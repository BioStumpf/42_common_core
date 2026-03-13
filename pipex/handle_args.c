/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:34:20 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/13 14:36:54 by dstumpf          ###   ########.fr       */
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

void	find_colon(struct s_dat *data, char *path)
{
	size_t	i;

	i = 0;
	data->colon = SIZE_MAX; 
	if (path[i] == ':')
	{
		data->colon = 0;
		return ;
	}
	while (data->path_split[i])
	{
		if (path[0] && ft_strncmp("::", path, 2) == 0)
		{
			data->colon = i;
			return ;
		}
		skip_char(&path, ':');
		path += ft_strlen(data->path_split[i]);
		i++;
	}
	if (path[0] == ':')
		data->colon = i;
}

void	split_path(struct s_dat *data, char **envp)
{
	char	*path;

	path = find_path(envp);
	data->path_split = ft_split(path, ':');
	if (!data->path_split)
		cleanup(data, 1, "ft_split");
	find_colon(data, path);
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

static bool	check_access(struct s_dat *data, int *status)
{
	if (access(data->program_path, F_OK) == 0)
	{
		if (access(data->program_path, X_OK) == 0)
			return (true);
		else
			*status = errno;
	}
	return (false);
}

static bool	check_path(struct s_dat *data, char *path, char *program, int *status)
{
	data->program_path = ft_pathjoin(path, program);
	if (!data->program_path)
		cleanup(data, 1, "ft_pathjoin");
	if (check_access(data, status))
		return (true);
	free(data->program_path);
	data->program_path = NULL;
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
		if (data->colon == i)
		{
			if (check_path(data, ".", program, &status))
				return ;
		}
		if (check_path(data, data->path_split[i], program, &status))
			return ;
		i++;
	}
	if (data->colon == i)
	{
		if (check_path(data, ".", program, &status))
			return ;
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
