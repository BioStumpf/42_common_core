/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstumpf <dstumpf@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/03/06 11:34:20 by dstumpf             #+#    #+#             */
/*   Updated: 2026/03/17 11:58:28 by dstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

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
