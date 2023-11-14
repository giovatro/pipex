/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:50:42 by gtroiano          #+#    #+#             */
/*   Updated: 2023/11/10 12:53:08 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void    pipex(char *cmd, char **envp)
{
    int fd[2];
    pid_t pid;

    pipe(fd);
    if (pipe(fd) == -1)
        error_func();
    pid = fork();
    if (pid < 0)
        error_func();
    if (pid == 0) 
    { //child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execute_cmd(cmd, envp);
        exit(EXIT_FAILURE);
    }
    else 
    { //parent process
        waitpid(pid, NULL, WNOHANG);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
    }
}

int main(int argc, char **argcv, char **envp)
{
    int fdin;
    int fdout;

    if (argc == 5) // number of arguments shold be set as 5
    {
        fdin = open_file(argv[1], INFILE); //open_fuile function
        if (fdin < 0)
            error_func();
        dup2(fdin, STDIN_FILENO);
        fdout = open_file(argv[4], OUTFILE);
        if (fdout < 0)
            error_func();
        dup2(fdout, STDOUT_FILENO);
        pipex(argv[2], envp); //function
        execute_cmd(argv[3], envp); //function 
    }
    else
        write(2, "Invalid number of arguments", 27);
    return (1);  //check what happens with 0  
}