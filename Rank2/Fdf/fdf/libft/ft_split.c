/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:13:28 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:31:38 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*dup_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	len;

	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, len);
	word[len] = '\0';
	return (word);
}

static void	free_split(char **arr, size_t count)
{
	while (count > 0)
		free(arr[--count]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	end = 0;
	while (s[end] && i < word_count)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		split[i] = dup_word(s, start, end);
		if (!split[i])
			return (free_split(split, i), NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}