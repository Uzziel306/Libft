/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:51:12 by asolis            #+#    #+#             */
/*   Updated: 2017/01/13 16:51:13 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*x;

	x = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		x = (char *)malloc(sizeof(char) * (len + 1));
		if (x)
		{
			ft_strcpy(x, (char *)s1);
			ft_strcat(x, s2);
		}
	}
	return (x);
}
