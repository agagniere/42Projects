/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:15:32 by angagnie          #+#    #+#             */
//   Updated: 2015/12/08 17:35:36 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIBFT_H
# define TESTLIBFT_H

# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

extern "C"
{
# include "libft.h"
}
# include "colors.h"
# include "macroes.h"
# include "ultimate.hpp"

# define BUSZ 128

char	*clear_buf(char *buf, char const *tocpy = "");

void	test_atoi(int (*ft)(const char *str));
void	test_bzero(void (*ft)(void * s, size_t n));

void	test_strlen(size_t (*ft)(const char *str));
void	test_allchar(int (*ft)(int c), int (*ref)(int c));
void	test_putnbr(void (*ft)(int n));
void	test_memset(void *(*ft)(void *b, int c, size_t length));
void	test_putstr(void (*ft)(char const *s));
void	test_memcpy(void *(*ft)(void *dst, const void *src, size_t n));
void	test_putchar_fd(void (*ft)(char c, int fd));
void	test_strcpy(char *(*ft)(char *dst, char const *src));
void    test_memchr(void *(*ft)(const void *s, int c, size_t n));
void	test_strlcat(size_t (*ft)(char *dst, const char *src, size_t size));
void	test_memcmp(int (*ft)(const void *s1, const void *s2, size_t n));
void	test_memmove(void *(*ft)(void *dst, const void *src, size_t len));
void	test_strcat(char *(*ft)(char *s1, const char *s2));

void	test_dyna(void);

#endif
