#include "libft.h"

size_t	ft_strlennum(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if(str[i] >= '0' && str[i] <= '9')
			j++;
		i++;
	}
	return (j);
}