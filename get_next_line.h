/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:55:05 by pconin            #+#    #+#             */
/*   Updated: 2016/01/13 16:19:50 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
#define BUFF_SIZE 32

int					get_next_line(int const fd, char ** line);
char                *ft_strsub(char const *s, unsigned int start, size_t len);
void                *ft_memalloc(size_t size);
void                ft_bzero(void *s, size_t n);
void                ft_putstr(char const *s);

#endif
