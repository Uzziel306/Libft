/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:09:57 by asolis            #+#    #+#             */
/*   Updated: 2017/01/14 23:10:00 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len(int l, int num, int n)
{
	if (n < 0)
		l += 1;
	while (num)
	{
		num /= 10;
		l++;
	}
	return (l);
}

static	char	*ultimatum(char *str, int n, int l)
{
	str[l] = '\0';
	while (n != 0)
	{
		str[--l] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		l;
	char	*str;
	int		num;

	l = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	l = len(l, num, n);
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str = ultimatum(str, n, l);
	return (str);
}
