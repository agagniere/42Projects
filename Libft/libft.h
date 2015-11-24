/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/24 13:58:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void    ft_bzero(void *s, size_t n);
int     ft_isalnum(int c);
int     ft_isalpha(int c);
int     ft_isascii(int c);
int     ft_iscntrl(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
void    *ft_memset(void *b, int c, size_t len);
char    *ft_stpcpy(char *dst, const char *src);
size_t	ft_strlen(char const *str);
int     ft_tolower(int c);
int     ft_toupper(int c);
