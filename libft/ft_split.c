/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:54 by gtroiano          #+#    #+#             */
/*   Updated: 2023/07/30 21:44:17 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_counter(char const *s, char c)
{
	int	words_number;

	words_number = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			words_number++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words_number);
}

static void	ft_split_s(char **array, char const *s, char c)
{
	size_t	word;
	size_t	len_s;
	size_t	sub_s;

	word = 0;
	sub_s = 0;
	while (*(s + sub_s))
	{
		len_s = 0;
		while (*(s + sub_s) == c)
			sub_s++;
		while (*(s + sub_s) != c && *(s + sub_s))
		{
			len_s++;
			sub_s++;
		}
		if (len_s)
			array[word] = (char *)malloc(sizeof(char) * (len_s + 1));
		if (!array[word])
			return ;
		ft_strlcpy(array[word++], (s + sub_s) - len_s, len_s + 1);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words_number;

	if (!s)
		return (NULL);
	words_number = ft_words_counter(s, c);
	array = (char **)malloc(sizeof(char *) * (words_number + 1));
	if (!array)
		return (NULL);
	array[words_number] = NULL;
	ft_split_s(array, s, c);
	return (array);
}
