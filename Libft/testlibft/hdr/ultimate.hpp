// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ultimate.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/30 16:55:54 by angagnie          #+#    #+#             //
//   Updated: 2015/11/30 20:17:36 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ULTIMATE_HPP
# define ULTIMATE_HPP

// # define END "\e[0;0m"
// # define RED "\e[1;31m"
// # define GREEN "\e[0;32m"

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <iostream>
# include <type_traits>

# define BUFSIZE 32

char    *strcln(char const *str, size_t size = 0);

template <bool Allocates, class FRet, class ...Args>
struct Checker
{};

template <class FRet, class ...Args>
struct Checker<true, FRet, Args...>
{
	static void		check(char *refret_buffer, char *ftret_buffer
						  , FRet const refret, FRet const ftret
						  , char const *original_buffer, Args const ...)
		{
			(void)original_buffer;
			(void)refret_buffer;
			(void)ftret_buffer;
			if (ftret == NULL && refret != NULL)
				printf("%s[Should not be NULL]", RED);
			else if (ftret == NULL && refret == NULL)
				printf("%s.", GREEN);
			else if (ftret != 0 && refret == NULL)
				printf("%s[Should be NULL]", RED);
			else if (strcmp(refret, ftret) == 0)
				printf("%s.", GREEN);
			else
				printf("%s[Wrong output]", RED);
			if (refret != NULL)
				free(refret);
			if (ftret != NULL)
				free(ftret);
			return ;
		}
};

template <class FRet, class ...Args>
struct Checker<false, FRet, Args...>
{
	static void		check(char const *refret_buffer, char const *ftret_buffer
						  , FRet const refret, FRet const ftret
						  , char const *original_buffer, Args const ...)
		{
			if (refret == ftret)
				printf("%s_", GREEN);
			else
				printf("%s[Wrong return value]", RED);
			if (memcmp(refret_buffer, ftret_buffer, BUFSIZE) != 0)
			{
				printf("%s>-----------/ Error \\-----------<%s\n", RED, END);
				printf("\tOriginal memory state : [%s]\n", strcln(original_buffer, BUFSIZE));
				printf("\tAfter your function   : [%s]\n", strcln(ftret_buffer, BUFSIZE));
				printf("\tWhereas it should be  : [%s]\n", strcln(refret_buffer, BUFSIZE));
			}
			else
				printf("%s.", GREEN);
			return ;
		}
};

template <bool Allocates = false
		  , class FRet, class ...FParams
		  , class ...Args>
void	fun_tester_na(FRet (*fref)(FParams...), FRet (*fft)(FParams...)
							  , char *buf, Args const ...args)
{
	char		original_buffer[BUFSIZE];
	char		refret_buffer[BUFSIZE];
	FRet		refret;
	FRet		ftret;

	memcpy(original_buffer, buf, BUFSIZE);		// original_buffer		<- buf
	refret = fref(buf, args...);				// buf			<~ fref
	memcpy(refret_buffer, buf, BUFSIZE);		// refret_buffer	<- buf	(<~ fref)
	memcpy(buf, original_buffer, BUFSIZE);		// buf			<- original_buffer
	ftret = fft(buf, args...);					// buf			<~ fft

	Checker<Allocates, FRet, Args...>::check(
		refret_buffer, buf, refret, ftret, original_buffer, args...);
	return ;
}

#endif
