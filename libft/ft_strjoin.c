/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:58:18 by gtroiano          #+#    #+#             */
/*   Updated: 2023/07/27 16:13:55 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_total;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = (char *)malloc(sizeof(char) * len_total);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, len_total);
	ft_strlcat(new_s, s2, len_total);
	return (new_s);
}
