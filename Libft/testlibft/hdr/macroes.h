/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macroes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:14:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/30 16:14:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROES_H
# define MACROES_H

# define SIZE_ARRAY(A) (sizeof((A)) / sizeof(*(A)))
# define STRIDE_ARRAY(A) (sizeof(*(A)))
# define END_ARRAY(A) ((void*)(A) + sizeof((A)))

# include "magic.hpp"

#define MARK(success, ok, ko) if (success)					\
		printf("%s%s", GREEN, #ok);							\
    else													\
	{														\
        printf("%s[%s]", RED, ft::valToString(ko).c_str());	\
	}														\

#define MARKF(success, ok, ko) fflush(stdout);					\
	if (!fork())												\
	{															\
		if (success)											\
			printf("%s%s", GREEN, #ok);							\
		else													\
			printf("%s[%s]", RED, ft::valToString(ko).c_str());	\
		exit(0);												\
	}															\
	else														\
	{															\
		wait(&status);											\
		if (status == 11)										\
			printf("%sS", RED);									\
		else if (status)										\
			printf("[%i]", status);								\
	}

# define FORK(FUN) printf("%s[", #FUN);						\
	fflush(stdout);											\
	if (!fork())											\
	{														\
		test_##FUN(&ft_##FUN);								\
		exit(0);											\
	}														\
	else													\
	{														\
		wait(&status);										\
		if (status == 11)									\
			printf("%sSegFault", RED);						\
		else if (status)									\
			printf("Exit code : %i", status);				\
	}														\
	printf("%s]\n", END);									\
	fflush(stdout)


# define TEST(FUN) printf("%s[", #FUN);			\
	fflush(stdout);								\
	test_##FUN(&ft_##FUN);						\
	printf("%s]\n", END);						\
	fflush(stdout)

# define TESTAC(FUN) printf("%s[", #FUN);		\
    test_allchar(&ft_##FUN, &FUN);				\
    printf("%s]\n", END)

#endif
