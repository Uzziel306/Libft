/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:23:30 by asolis            #+#    #+#             */
/*   Updated: 2017/01/16 19:23:31 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nextword(const char *s, char c, size_t *ele)
{
	size_t	i;

	i = 0;
	while (s[*ele] == c)
		*ele += 1;
	i = *ele;
	while (s[*ele])
	{
		if (s[*ele] == c)
			break ;
		*ele += 1;
	}
	return (ft_strsub(s, i, *ele - i));
}

static int	ft_wordcount(char const *s, char c)
{
	int		t;

	t = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (*(s + 1) == c || !(*(s + 1)))
				t++;
			s++;
		}
	}
	return (t);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		words;
	size_t	element;

	index = 0;
	element = 0;
	words = ft_wordcount(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	while (index < words)
		str[index++] = ft_nextword(s, c, &element);
	str[index] = 0;
	return (str);
}
