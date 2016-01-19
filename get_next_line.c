/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:29:38 by pconin            #+#    #+#             */
/*   Updated: 2016/01/19 14:48:01 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFSIZE	1024

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

char    *ft_alloc(char *l, int j)
{
	int   i;
	char  *new;

	i = 0;
	new = NULL;
	if (j == 0 && ((l = malloc((BUFFSIZE + 1) * sizeof(char))) == NULL))
		return (-1);
	if (j == 0)
		return (l);
	if ((new = malloc((j + BUFFSIZE + 1) * sizeof(char))) == NULL)
		return (-1);
	while (i <= j)
	{
		new[i] = l[i];
		i++;
	}
	new[i] = '\0';
	free(l);
	return (new);
}

char *ft_get_next_line(int const fd, char **l)
{
	static int	i = 0;
	static int	j = 0;
	static int	k = 0;
	static char	buff[BUFFSIZE];

	if (i == 0 && (k = read(fd, buff, BUFFSIZE)) == 0)
		return (finish(l[nb], j));
	if ((l[nb] = ft_alloc(l[nb], j)) == NULL)
		return (0);
	while (i < k)
	{
		if (buff[i] == '\n')
		{
			i++;
			l[j] = '\0';
			j = 0;
			nb++;
			return (1);
		}
		if (!buff[i])
			return (0);
		*l[j] = buff[i];
		i++;
		j++;
	}
	i = 0;
	return (get_next_line(fd));
}

