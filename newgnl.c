/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:46:39 by pconin            #+#    #+#             */
/*   Updated: 2016/01/20 17:43:45 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 5
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_put_in_line(char *tmp, char *line)
{
	int l;

	l = 0;
	while (tmp[l] != '\n')
	{
		line[l] = tmp[l];
		l++;
	}
}
int		found_newline(char *tmp)
{
	int i;

	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*tmp = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	
	if (tmp == NULL)
		tmp = ft_memalloc(BUFF_SIZE + 1);
	while (found_newline(tmp) != 1)
	{
 		ret = read(fd, buf, BUFF_SIZE);
		tmp = ft_strjoin(tmp, buf);
//		free(buf);
	}
	if (found_newline(tmp) == 1)
	{
		ft_put_in_line(tmp, *line);
		tmp = ft_strchr(tmp, '\n');
	}
	if (ret != 0 && ret != -1)
		ret = 1;
	return (ret);
}
