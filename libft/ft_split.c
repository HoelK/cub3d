/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:11:17 by hkeromne          #+#    #+#             */
/*   Updated: 2025/10/27 21:11:17 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_to_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_words(const char *str, char sep)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
			word_count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (word_count);
}

static char	**ft_alloc_secure(char **res, int id, int len)
{
	res[id] = malloc(sizeof(char) * (len + 1));
	if (res[id] == NULL)
	{
		while (id >= 0)
			free(res[id--]);
		free(res);
		res = NULL;
		return (res);
	}
	return (res);
}

static char	**ft_wordalloc(char **res, const char *str, char c, int word_count)
{
	int	i;
	int	j;
	int	id;
	int	len_word;

	i = 0;
	j = 0;
	id = 0;
	while (str[j] && i < word_count)
	{
		while (str[j] && str[j] == c)
			j++;
		len_word = len_to_char(&str[j], c);
		res = ft_alloc_secure(res, i, len_word);
		if (res == NULL)
			return (res);
		while (str[j] && str[j] != c)
			res[i][id++] = str[j++];
		res[i][id] = '\0';
		id = 0;
		i++;
	}
	return (res);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		word_count;
	char	**result;

	i = 0;
	word_count = count_words(str, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	while (i <= word_count)
		result[i++] = NULL;
	result = ft_wordalloc(result, str, c, word_count);
	return (result);
}
