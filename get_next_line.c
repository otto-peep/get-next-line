/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:40:29 by pconin            #+#    #+#             */
/*   Updated: 2016/01/13 16:02:21 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>

int		ft_mallocandput(char *temp, char **line, int len, int nb)
{
	int a;

	a = 0;
//	ft_putstr(temp);
//	ft_putstr("\n");
	line[nb] = (char *) malloc(sizeof(char) * len);
	while (a != len)
	{
		line[nb][a] = temp[a];
		a++;
	}
	line[nb][a] = '\0';
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static int index;
	static int nb;
	char temp[BUFF_SIZE];
	int memory;
	int ret;

//	printf("%i\n", index);
//	ft_putstr("before read");
	ret = read(fd, temp, BUFF_SIZE);
//	ft_putstr(temp);
	if (ret == -1)
		return (-1);
//	ft_putstr("afterread");
	memory = index;
	while (temp[index] != '\n' && temp[index])
		index++;
	ret = ft_mallocandput(ft_strsub(temp, memory, index - memory),
		   	line, index - memory, nb);
	nb++;
//	index++;
	return (0);
}
