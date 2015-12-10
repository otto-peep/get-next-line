/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:13 by pconin            #+#    #+#             */
/*   Updated: 2015/12/08 17:42:27 by pconin           ###   ########.fr       */
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

	fd = open("readme.txt", O_RDWR);
//	printf("%s", "hello\nworld\ngoood\nmorning");
	ret = get_next_line(fd, tab);
	//		printf("%i\n%s\n%s\n", ret, tab[1], tab[2]);
	return (0);
}
