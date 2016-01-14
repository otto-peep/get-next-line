/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:55:05 by pconin            #+#    #+#             */
/*   Updated: 2016/01/14 18:43:21 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
#define BUFF_SIZE 5

int		get_next_line(int const fd, char ** line);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
void    *ft_memalloc(size_t size);
void    ft_bzero(void *s, size_t n);
void    ft_putstr(char const *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);

#endif
