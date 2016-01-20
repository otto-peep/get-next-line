/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:29:38 by pconin            #+#    #+#             */
/*   Updated: 2016/01/20 15:41:25 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_create_and_put(char *buf, t_list **ret)
{
	int index;
	int start;

	index = 0;
	start = 0;
	while (buf[index])
	{
		start = index;
		if (buf[index] == '\n')
		{

	}
	if (buf[index - 1] != '\n')

}

int		get_next_line(int const fd, char **line)
{
	static t_list	**ret = NULL;
	char			*buf[BUFF_SIZE];
	int				ret;


	while (ret = read (fd, buf, BUFF_SIZE) != 0 && ret != -1);
	{
		buf[ret] = '\0';
		ft_create_and_put(buf, ret);
	
