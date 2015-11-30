// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ultimate.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/30 16:55:54 by angagnie          #+#    #+#             //
//   Updated: 2015/11/30 17:29:21 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ULTIMATE_HPP
# define ULTIMATE_HPP

# include <string.h>
# include <stdio.h>

# define BUFSIZE 32

char    *strcln(char const *str, size_t size = 0);

template <
	class FRet
	, class ...FParams
	, class ...Args
	>
void			fun_tester_na(
	FRet (*fref)(FParams...)
	, FRet (*fft)(FParams...)
	, char *buf, Args ...args)
{
	char  savebuff[BUFSIZE];
	char  savebuff2[BUFSIZE];

	memcpy(savebuff, buf, BUFSIZE);		// savebuff		<- buf
	auto retref = fref(buf, args...);	// buf			<~ fref
	memcpy(savebuff2, buf, BUFSIZE);	// savebuff2	<- buf	(<~ fref)
	memcpy(buf, savebuff, BUFSIZE);		// buf			<- savebuff
	auto retft = fft(buf, args...);		// buf			<~ fft

	if (retref == retft)
		printf("%s_", GREEN);
	else
		printf("%s[Wrong return value]", RED);
	if (memcmp(savebuff2, buf, BUFSIZE) != 0)
	{
		printf("%s>-----------/ Error \\-----------<%s\n", RED, END);
		printf("\tOriginal memory state : [%s]\n", strcln(savebuff, BUFSIZE));
		printf("\tAfter your function   : [%s]\n", strcln(savebuff2, BUFSIZE));
		printf("\tWhereas it should be  : [%s]\n", strcln(buf, BUFSIZE));
	}
	else
		printf("%s.", GREEN);
	return ;
}

#endif
