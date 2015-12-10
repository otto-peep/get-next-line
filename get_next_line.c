/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:15:54 by pconin            #+#    #+#             */
/*   Updated: 2015/12/08 17:42:30 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#define BUFF_SIZE 10

void	ft_putlinetab(char *str, int begin, unsigned int end, int line, char **tab)
{
	int index;

	printf("%s", "a");
	index = 0;
	tab[line] = (char *) malloc(sizeof(char) * (end - begin));
	while (begin < end)
	{
		tab[line][index] = str[begin];
		index++;
		begin++;
	}
	tab[line][index] = '\0';
}

int	fd_endline(char *str, unsigned int ind, int line, char **tab )
{
	int begin;

	printf("%s", "b");
	begin = ind;
	while (str[ind])
	{
		if (str[ind] == '\n' || str[ind] == '4') 
		{	
			ft_putlinetab(str, begin, ind, line, tab);
			ind++;
			line++;
			return (0);			
		}
		ind++;
	}
	return (-1);
}

int	ft_countline(char *str, char **tab)
{
	int a;

	printf("%s", "c");
	a = 0;
	while (str[a] != '4')
	{
		if (str[a] == '\n')
			while (str[a] != '\n')
				a++;
	}
	tab = (char **)malloc(sizeof(char*) * a);
	if (tab == NULL)
		return (-1);
	return (0);
}


int			get_next_line(int const fd, char **line)
{
	char	*buff;
	int		ret;
	static int	nbline = 0;
	static unsigned int	index = 0;

	printf("%s", "d");
	ret = read(fd, buff, BUFF_SIZE);
	printf("\n%d", errno);
	if (ret == -1)
		return (0);
//	ret = ft_countline(buff, line);
//	ret =  fd_endline(buff, nbline, index, line);
	printf("%s", "e");
	return (ret);
}
