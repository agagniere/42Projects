/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macroes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:14:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 15:01:14 by angagnie         ###   ########.fr       */
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
		printf("%s[Failed with : %i]", RED, (entree))

# define YDNHS(success, entree) if (success)						\
		OK;															\
	else															\
		printf("%s[Failed with : \"%s\"]", RED, (entree))

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
			printf("%s[SegFault]", RED);					\
		else if (status)									\
			printf("[Exit code : %i]", status);				\
	}														\
	printf("%s]\n", END);									\
	fflush(stdout)

# define TEST(FUN) printf("%s[", #FUN);			\
	fflush(stdout);								\
    test_##FUN(&ft_##FUN);                      \
    printf("%s]\n", END);						\
	fflush(stdout)

# define TESTAC(FUN) printf("%s[", #FUN);		\
    test_allchar(&ft_##FUN, &FUN);				\
    printf("%s]\n", END)

#endif
