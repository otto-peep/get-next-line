/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:13 by pconin            #+#    #+#             */
/*   Updated: 2016/01/21 13:43:51 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
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
	while (a != 1)
	{
		ret = get_next_line(0, tab);
//		ft_putstr(*tab);
//		ft_putnbr(ret);
//		ft_putstr("\n");
		a++;
	}


	return (0);
}
