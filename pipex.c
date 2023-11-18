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


static void	child(int *fd, char *infile, , char *cmd, char **envp)
{
	int		infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infd == -1)
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

	waitpid(pid, NULL, WNOHANG); //WNOHANG was 0
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_fd == -1)
	{
		perror("Open outfile error");
		exit(1);
	}
	dup2(outile_fd, 1);
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
		perror("Pipe");
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		exit(-1);
	}
	else if (pid == 0)
		child(fd, argv[0], argv[1], envp); //CHANGE 0 and 1 to 1 and 2
	else
		parent(fd, argv[2], argv[3], envp);
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		perror("Invalid number of arguments");
		exit(1);
	}
	pipex(argv + 1, envp);
	return (0);
}