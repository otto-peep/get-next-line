/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:40:29 by pconin            #+#    #+#             */
/*   Updated: 2016/01/14 18:56:12 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	char	*rtn;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		rtn = (char *)malloc(sizeof(char) * (size + 1));
		if (rtn == NULL)
			return (NULL);
		ft_strcpy(rtn, s1);
		ft_strcat(rtn, s2);
		return (rtn);
	}
	if (s1 && !s2)
		return (ft_strdup(s1));
	else
		return (ft_strdup(s2));
}

int		ft_check(char *temp, int buf)
{
	int a;

	a = 0;
	while (buf > 0)
	{
		if (temp[a] == '\n' || !(temp[a]))
			return (1);
		buf--;
		a++;
	}
	return (0);	
}

int		get_next_line(int const fd, char **line)
{
	static int *index;
	static int nb;
	char temp[BUFF_SIZE + 1];
	int bool;
	int ret;

	bool = 0;
	while (bool != 1)
	{
		ft_putstr("avant le strjoin \n ");
		&line[nb] = *ft_strjoin(line[nb], temp);
		ret = read(fd, temp, BUFF_SIZE);
		temp[BUFF_SIZE] = '\0';
		bool = ft_check(temp, BUFF_SIZE);
		ft_putstr("voila le tab : \n");
		ft_putstr(line[nb]);
		ft_putstr("\n");
	}
	nb++;
	return (ret);
}
