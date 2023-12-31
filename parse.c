/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:11:56 by gtroiano          #+#    #+#             */
/*   Updated: 2023/11/20 17:39:07 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	**env_paths;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (ft_split("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:", ':'));
	tmp = envp[i] + 5;
	env_paths = ft_split(tmp, ':');
	i = 0;
	while (env_paths[i])
	{
		tmp = env_paths[i];
		env_paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
	return (env_paths);
}

char	*find_cmd_path(char *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	path = get_path(path);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*pathname;

	args = ft_split(cmd, ' ');
	pathname = find_cmd_path(args[0], envp);
	execve(pathname, args, envp);
	write(2, "pipex: ", 7);
	write(2, "command not found: ", 20);
	write(2, cmd, ft_strlen(cmd));
	exit(1);
}
