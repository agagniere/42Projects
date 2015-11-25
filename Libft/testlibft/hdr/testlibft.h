/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 17:01:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIBFT_H
# define TESTLIBFT_H

# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include "libft.h"
# include "colors.h"
# include "macroes.h"

void	test_atoi(int (*ft)(const char *str));
void	test_strlen(size_t (*ft)(const char *str));
void	test_tolower(int (*ft)(int c));
void	test_toupper(int (*ft)(int c));

#endif
