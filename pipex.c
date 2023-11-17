/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:50:42 by gtroiano          #+#    #+#             */
/*   Updated: 2023/11/17 15:57:04 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	if (pipe(fd) == -1)
		error_func();
	pid = fork();
	if (pid < 0)
		error_func();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_cmd(cmd, envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = open_file(argv[1], INFILE);
		if (fdin < 0)
			error_func();
		dup2(fdin, STDIN_FILENO);
		fdout = open_file(argv[4], OUTFILE);
		if (fdout < 0)
			error_func();
		dup2(fdout, STDOUT_FILENO);
		pipex(argv[2], envp);
		execute_cmd(argv[3], envp);
	}
	else
		write(2, "Invalid number of arguments", 27);
	return (1);
}
