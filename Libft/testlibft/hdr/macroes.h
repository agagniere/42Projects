/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macroes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:14:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/27 12:15:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROES_H
# define MACROES_H

# define SIZE_ARRAY(A) (sizeof((A)) / sizeof(*(A)))
# define STRIDE_ARRAY(A) (sizeof(*(A)))
# define END_ARRAY(A) ((void*)(A) + sizeof((A)))

# define OK printf("%s.", GREEN)

#define MARK(success) if (success)				\
		OK;										\
    else										\
        printf("%sX", RED)

# define ONFAIL(success, message) if (success)	\
        OK;										\
	else										\
		printf("%s[%s]", RED, (message))

# define YDNHI(success, entree) if (success)						\
		OK;															\
	else															\
		printf("%s[%i]", RED, (entree))

# define YDNHS(success, entree) if (success)						\
		OK;															\
	else															\
		printf("%s[You do not handle : \"%s\"]", RED, (entree))

# define TEST(FUN) printf("%s[", #FUN);			\
    test_##FUN(&ft_##FUN);                      \
    printf("%s]\n", END)

# define TESTAC(FUN) printf("%s[", #FUN);		\
    test_allchar(&ft_##FUN, &FUN);				\
    printf("%s]\n", END)

#endif
