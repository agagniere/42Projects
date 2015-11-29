/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:18:27 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 16:50:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static const char	*next_word(const char *str, char d)
{
	while (*str == d && *str != '\0')
		str++;
	return (*str == '\0' ? NULL : str);
}

/*
** end_word takes a string pointing to a word
*/

static const char	*end_word(const char *str, char d)
{
	while (*str != d && *str != '\0')
		str++;
	return (str - 1);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**ans;
	char const	*ptr;
	int			word_count;

	word_count = 0;
	ptr = s;
	while ((ptr = next_word(ptr, c)) != NULL)
	{
		word_count++;
		ptr = end_word(ptr, c) + 1;
	}
	if (!(ans = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	ans[word_count] = NULL;
	word_count = 0;
	while ((s = next_word(s, c)) != NULL)
	{
		ptr = s;
		s = end_word(s, c) + 1;
		ans[word_count++] = ft_strsub(ptr, 0, s - ptr);
	}
	return (ans);
}
