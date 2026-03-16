/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:34:20 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/16 18:09:23 by dstumpf          ###   ########.fr       */
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

static bool	check_access(struct s_dat *data)
{
	if (access(data->program_path, F_OK) == 0)
	{
		if (access(data->program_path, X_OK) == 0)
			return (true);
		else
			data->access_state = 126;
	}
	return (false);
}

bool	check_if_path(struct s_dat *data, char *program)
{
	if (ft_strchr(program, '/'))
	{
		data->program_path = ft_strdup(program);
		if (!data->program_path)
			cleanup(data, 1, NULL);
		if (check_access(data))
			return (true);
		cleanup(data, data->access_state, program);
	}
	return (false);
}

static bool	check_path(struct s_dat *data, char *path, char *program)
{
	data->program_path = ft_pathjoin(path, program);
	if (!data->program_path)
		cleanup(data, 1, "ft_pathjoin");
	if (check_access(data))
		return (true);
	free(data->program_path);
	data->program_path = NULL;
	return (false);
}

void	get_program_path(struct s_dat *data, char *program)
{
	size_t	i;

	i = 0;
	if (!program[0])
		cleanup(data, 127, "");
	while (data->path_split[i])
	{
		if (data->colon == i)
		{
			if (check_path(data, ".", program))
				return ;
		}
		if (check_path(data, data->path_split[i], program))
			return ;
		i++;
	}
	if (data->colon == i)
	{
		if (check_path(data, ".", program))
			return ;
	}
	if (data->access_state == 126)
		errno = EACCES;
	cleanup(data, data->access_state, program);
}

void	get_program_av(struct s_dat *data, char *arg)
{
	data->program_av = ft_split(arg, ' ');
	if (!data->program_av)
		cleanup(data, 1, "ft_split");
}
