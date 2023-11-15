/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:23:50 by gtroiano          #+#    #+#             */
/*   Updated: 2023/11/15 14:30:23 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

# define STDIN 0
# define STDOUT 1

# define INFILE 0
# define OUTFILE 1

void	error_func(void);
int		open_file(char *file, int flag);
void	execute_cmd(char *cmd, char **envp);

#endif
