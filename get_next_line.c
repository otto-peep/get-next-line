/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:18:19 by pconin            #+#    #+#             */
/*   Updated: 2016/01/25 19:43:15 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

char	*ft_strnl(const char *s)
{
	int		a;
	char	*b;

	b = (char *)s;
	a = 0;
	while (b[a] != '\n' && b[a])
		a++;
	if (b[a] == '\n')
		return (&b[a + 1]);
	else
		return (NULL);
}

char	*ft_put_in_line(char *tmp, int r)
{
	char *ret;
	int		len;

	len = 0;
	while (tmp[len] != '\n' || (tmp[len] && r == 0))
		len++;
	ret = (char *) malloc (sizeof(char) * len);
	len = 0;
	while (tmp[len] != '\n' || (tmp[len] && r == 0))
	{
		ret[len] = tmp[len];
		len++;
	}
	ret[len] = '\0';
	return (ret);
}
int		found_newline(char *tmp, int ret)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n' || (!tmp[i] && ret == 0))
			return (1);
		i++;
	}
	return (0);
}
int		get_next_line(int const fd, char **line)
{
	static char	*tmp = NULL;
	char		buf[BUFF_SIZE + 1];
	static	int			ret = 0;

	*line = ft_strnew(0);
	ft_bzero(buf, BUFF_SIZE);
	if (tmp == NULL)
		tmp = ft_memalloc(BUFF_SIZE + 1);
	while (found_newline(tmp, ret) != 1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	if (found_newline(tmp, ret) == 1)
	{
		*line = ft_put_in_line(tmp, ret);
		tmp = ft_strnl(tmp);
	}
	if (ret != 0 && ret != -1)
		ret = 1;
	return (ret);
}
