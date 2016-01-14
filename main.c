/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:13 by pconin            #+#    #+#             */
/*   Updated: 2016/01/14 18:48:58 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int ret;
	char **tab;
	int fd;
	int a;

	a = 0;
//	fd = open("readme.txt", O_RDWR);
	fd = 0;
	tab = NULL;
	while (a != 4)
	{
		//ft_putstr("whilemain");
		ret = get_next_line(fd, tab);

//		ft_putstr(tab[0]);
		ft_putstr("dans la boucle du main \n");
		a++;
	}


	return (0);
}
