/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:32:03 by asolis            #+#    #+#             */
/*   Updated: 2017/01/12 20:32:03 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		mstr[i] = f(i, s[i]);
	mstr[i] = '\0';
	return (mstr);
}
