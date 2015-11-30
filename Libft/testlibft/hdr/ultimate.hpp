// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ultimate.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/30 16:55:54 by angagnie          #+#    #+#             //
//   Updated: 2015/11/30 18:02:51 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ULTIMATE_HPP
# define ULTIMATE_HPP

# include <string.h>
# include <stdio.h>

# define BUFSIZE 32

char    *strcln(char const *str, size_t size = 0);

template <
	bool Allocates = false
	, class FRet
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
	auto	retref = fref(buf, args...);	// buf			<~ fref
	memcpy(savebuff2, buf, BUFSIZE);	// savebuff2	<- buf	(<~ fref)
	memcpy(buf, savebuff, BUFSIZE);		// buf			<- savebuff
	auto	retft = fft(buf, args...);		// buf			<~ fft

	if (Allocates == false)
	{
		if (retref == retft)
			printf("%s_", GREEN);
		else
			printf("%s[Wrong return value]", RED);
		if (memcmp(savebuff2, buf, BUFSIZE) != 0)
		{
			printf("%s>-----------/ Error \\-----------<%s\n", RED, END);
			printf("\tOriginal memory state : [%s]\n", strcln(savebuff, BUFSIZE));
			printf("\tAfter your function   : [%s]\n", strcln(buf, BUFSIZE));
			printf("\tWhereas it should be  : [%s]\n", strcln(savebuff2, BUFSIZE));
		}
		else
			printf("%s.", GREEN);
	}
	else
	{
		// ne pas rentrer ici si le type de retour est un int
		if (retft == 0 && retref != 0)
			printf("%s[0 returned]", RED);
		else if (retft == 0 && retref == 0)
			printf("%s.", GREEN);
		else if (retft != 0 && retref == 0)
			printf("%s[Should be NULL]", RED);
		else if (strcmp((char*)(void*)retref, (char*)(void*)retft) == 0)
			printf("%s.", GREEN);
		else
			printf("%s[Wrong output]", RED);
		if (std::is_pointer<FRet>::value)
		{
			free((void*)retref);
			free((void*)retft);
		}
	}
	return ;
}

#endif
