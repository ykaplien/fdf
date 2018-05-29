/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:08:19 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 21:57:11 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	size_t	c_word;
	size_t	ind;

	c_word = 0;
	ind = 0;
	while (s[ind])
	{
		if (s[ind - 1] == c && s[ind] != c)
			c_word++;
		ind++;
	}
	return (c_word);
}

static int	ft_mallochu(size_t words, char **res, const char *s, char c)
{
	size_t	ind;
	size_t	w_len;
	size_t	w_num;

	ind = 0;
	w_len = 0;
	w_num = 0;
	while (words && s[ind])
	{
		if (s[ind] != c)
		{
			if (s[ind + 1] == c || s[ind + 1] == '\0')
			{
				res[w_num] = (char *)malloc(sizeof(char) * (w_len + 1));
				if (!res[w_num])
					return (0);
				w_len = -1;
				w_num++;
				words--;
			}
			w_len++;
		}
		ind++;
	}
	return (1);
}

static void	ft_splitcopy(size_t words, char **res, const char *s, char c)
{
	size_t	ind;
	size_t	r_ind;
	size_t	word;

	word = 0;
	ind = 0;
	r_ind = 0;
	while (s[ind] && word < words)
	{
		if (s[ind] != c)
		{
			res[word][r_ind] = s[ind];
			r_ind++;
			if (s[ind + 1] == c || s[ind + 1] == '\0')
			{
				res[word][r_ind] = '\0';
				r_ind = 0;
				word++;
			}
		}
		ind++;
	}
	res[word] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	ind;
	size_t	words;

	ind = 0;
	words = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (ft_mallochu(ft_count_words(s, c), res, s, c))
	{
		ft_splitcopy(ft_count_words(s, c), res, s, c);
		return (res);
	}
	return (NULL);
}
