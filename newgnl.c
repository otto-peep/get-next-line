/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:46:39 by pconin            #+#    #+#             */
/*   Updated: 2016/01/21 17:43:53 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 5
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_put_in_line(char *tmp)
{
	char *ret;
	int		len;

	len = 0;
	while (tmp[len] != '\n')
		len++;
	ret = (char *) malloc (sizeof(char) * len);
	len = 0;
	while (tmp[len] != '\n')
	{
		ret[len] = tmp[len];
		len++;
	}
	tmp[len] = '\0';
	return (ret);
}
int		found_newline(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
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
//	ft_putstr(tmp);
	while (found_newline(tmp) != 1)
	{
//		ft_putnbr(found_newline(tmp));
 		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1 || ret == 0)
			return (ret);
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
//		ft_putstr("tmp:");
//		ft_putstr(tmp);
	}
//	ft_putstr("afficher tmp apres while : \n");
	ft_putstr(tmp);
	if (found_newline(tmp) == 1)
	{
		*line = ft_put_in_line(tmp);
//		ft_putstr("apres putinline");
		printf("%s", tmp);
		tmp = ft_strchr(tmp, 10);
		printf("%s", tmp);
	}
	if (ret != 0 && ret != -1)
		ret = 1;
	return (ret);
}
