/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:13 by pconin            #+#    #+#             */
/*   Updated: 2016/01/26 19:05:44 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int ret;
	char *line = NULL;

	while ((ret = get_next_line(0, &line)) > 0)
	{
//		ft_putstr("avant putstr");
		ft_putstr(line);
		ft_putnbr(ret);
		ft_putstr("\n");
		free(line);
		line = NULL;
	}
//	ft_putstr(line);
	ft_putnbr(ret);

	return (0);
}
