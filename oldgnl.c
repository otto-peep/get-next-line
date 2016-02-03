/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:49:59 by pconin            #+#    #+#             */
/*   Updated: 2016/02/03 17:01:11 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

int		found_newline2(char *tmp)
{
	int index;

	index = 0;
	if (!tmp)
		return (0);
	while (tmp[index] && tmp[index] != '\n')
		index++;
	if (tmp[index] == '\n')
		return (index + 1);
	else
		return (0);
}

int		found_newline(char *tmp, int ret)
{
	int index;

	index = 0;
	if (!tmp)
		return (0);
	while (tmp[index] && tmp[index] != '\n')
		index++;
	if (tmp[index] == '\n' || (!tmp[index] && ret == 0))
		return (index);
	else
		return (0);
}

void	ft_read(int fd, char **tmp, int *ret)
{
	char	*buf;
	char	*mem;

	buf = ft_strnew(BUFF_SIZE + 1);
	*ret = read(fd, buf, BUFF_SIZE);
	if (*ret == -1)
		return ;
	mem = *tmp;
	*tmp = ft_strjoin(*tmp, buf);
	free(mem);
	free(buf);
	return ;
}

int		get_next_line(int const fd, char **line)
{
	static char *tmp;
	int			ret;
	char		*mem;

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	while (tmp == NULL || (found_newline(tmp, ret) == 0 && ret >= 0))
	{
		ft_read(fd, &tmp, &ret);
		if (ret <= 0)
			break ;
	}
	if (ret == -1)
		return (-1);
	*line = ft_strsub(tmp, 0, found_newline(tmp, ret));
	mem = tmp;
	tmp = ft_strsub(tmp, found_newline2(tmp, ret) + 1, ft_strlen(tmp));
	free(mem);
	if (ft_strlen(tmp) == 0 && ret == 0 && !line[0][0])
		return (0);
	return (1);
}
