/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:50:42 by gtroiano          #+#    #+#             */
/*   Updated: 2023/11/19 11:58:55 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(int *fd, char *infile, char *cmd, char **envp)
{
	int		infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd == -1)
	{
		perror("Open infile error");
		exit(1);
	}
	dup2(infile_fd, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	execute_cmd(cmd, envp);
}

static void	parent(int *fd, char *cmd, char *outfile, char **envp)
{
	int	outfile_fd;

	wait(NULL);
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile_fd == -1)
	{
		perror("Open outfile error");
		exit(1);
	}
	dup2(outfile_fd, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	execute_cmd(cmd, envp);
}

void	pipex(char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	if (pipe(fd) == -1)
	{
		perror("Pipe error");
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(-1);
	}
	else if (pid == 0)
		child(fd, argv[1], argv[2], envp);
	else
		parent(fd, argv[3], argv[4], envp);
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		perror("Incorrect number of arguments");
		exit(1);
	}
	pipex(argv, envp);
	return (0);
}
