#include "libft.h"

int	ft_len(char *s)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	ft_solve(char **line, char *stc_buf)
{
	char *i;
	char *temp;

	if ((i = ft_strchr(stc_buf, '\n')) != 0)
	{
		temp = ft_strsub(stc_buf, 0, ft_strlen(stc_buf) - ft_strlen(i));
		ft_memmove(stc_buf, &i[1], ft_strlen(&i[1]) + 1);
		*line = ft_strdup(temp);
		return (1);
	}
	if (ft_len(stc_buf) == 0 && ft_strlen(stc_buf) > 0)
	{
		*line = ft_strdup(stc_buf);
		*stc_buf = '\0';
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char *stc_buff = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*temp2;
	int			ret;

	if (fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (stc_buff == NULL)
		stc_buff = ft_strnew(0);
	while (!ft_strchr(stc_buff, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		temp2 = ft_strjoin(stc_buff, buff);
		stc_buff = temp2;
	}
	return (ft_solve(line, stc_buff));
}