/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:22 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:39:44 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*answer;

	if (*little == '\0')
		return ((char *)big);
	answer = (char *)big;
	i = 0;
	while (answer[i] != '\0')
	{
		j = 0;
		while (little[j] == answer[i + j])
		{
			if (little[j + 1] == '\0')
				return (answer + i);
			j++;
		}
		i++;
	}
	return (0);
}
