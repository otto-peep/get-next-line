/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:06:11 by pconin            #+#    #+#             */
/*   Updated: 2016/01/19 18:07:47 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*finish(char *l, int j)
{
	static int    tmp = 0;

	if (j == 0)
		return (0);
	if (tmp == 0)
	{
		tmp = 1;
		return (l);
	}
	else
		return (0);
}

char    *my_realloc(char *l, int j)
{
	int   i;
	char  *new;

	i = 0;
	new = NULL;
	if (j == 0 && ((l = malloc((BUFFSIZE + 1) * sizeof(char))) == NULL))
		return (0);
	if (j == 0)
		return (l);
	if ((new = malloc((j + BUFFSIZE + 1) * sizeof(char))) == NULL)
		return (0);
	while (i <= j)
	{
		new[i] = l[i];
		i++;
	}
	new[i] = '\0';
	free(l);
	return (new);
}

char	*my_get_next_line(const int fd)
{
	static int    i = 0;
	static int    j = 0;
	static int    k = 0;
	static char   buff[BUFFSIZE];
	static char   *l = NULL;

	if (i == 0 && (k = read(fd, buff, BUFFSIZE)) == 0)
		return (finish(l, j));
	if ((l = my_realloc(l, j)) == NULL)
		return (0);
	while (i < k)
	{
		if (buff[i] == '\n')
		{
			i++;
			l[j] = '\0';
			j = 0;
			return (l);
		}
		l[j] = buff[i];
		i++;
		j++;
	}
	i = 0;
	return (my_get_next_line(fd));
}
