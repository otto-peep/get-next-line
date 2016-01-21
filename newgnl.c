/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:46:39 by pconin            #+#    #+#             */
/*   Updated: 2016/01/21 13:53:29 by pconin           ###   ########.fr       */
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
		ft_putstr("inside if \n");
		line[l] = tmp[l];
		ft_putstr("after");
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
//	ft_putstr("beforewhile");
	while (found_newline(tmp) != 1)
	{
//		ft_putnbr(found_newline(tmp));
 		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
//		ft_putstr(buf);
		tmp = ft_strcpy(tmp, buf);
		ft_putstr(tmp);
//		free(buf);
	}
//	ft_putstr(tmp);
//	ft_putstr("\n");
	if (found_newline(tmp) == 1)
	{
		ft_putstr("avant putinline \n");
		ft_put_in_line(tmp, *line);
		ft_putstr("avant strchr \n");
		tmp = ft_strchr(tmp, '\n');
	}
	if (ret != 0 && ret != -1)
		ret = 1;
	return (ret);
}
