/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:38:01 by gtroiano          #+#    #+#             */
/*   Updated: 2023/11/17 15:57:53 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_func(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int flag)
{
	if (flag == INFILE)
	{
		if (!access(file, F_OK | X_OK))
		{
			error_func();
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_RDWR | O_CREAT | O_TRUNC, 0644));
}
