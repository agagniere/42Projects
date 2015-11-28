/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 15:42:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIBFT_H
# define TESTLIBFT_H

# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"
# include "colors.h"
# include "macroes.h"

char	*strcln(char *str);

void	test_atoi(int (*ft)(const char *str));
void	test_bzero(void (*ft)(void * s, size_t n));

void	test_strlen(size_t (*ft)(const char *str));
void	test_allchar(int (*ft)(int c), int (*ref)(int c));
void	test_putnbr(void (*ft)(int n));
void	test_memset(void *(*ft)(void *b, int c, size_t length));
void	test_putstr(void (*ft)(char const *s));
void	test_memcpy(void *(*ft)(void *dst, const void *src, size_t n));
void	test_putchar_fd(void (*ft)(char c, int fd));

# define BUSZ 100

#endif
