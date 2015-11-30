// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/30 15:29:18 by angagnie          #+#    #+#             //
//   Updated: 2015/11/30 16:28:00 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"
#define ASSERT(PRED) printf("%d\n", PRED)

#define BUFSIZE 32

template <
	class FRet
	, class ...FParams
	, class ...Args
	, class Fun = FRet (*)(FParams...)
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
		printf("%s >-----------/ Error \\-----------<\n", RED);
		fflush(stdout);
		printf("\t\tYour function %p failed\n", fft);
	}
	else
		printf("%s.", GREEN);
	return ;
}


char *make_buf(char *buf, char const *tocpy = "")
{
	bzero(buf, BUFSIZE);
	strcpy(buf, tocpy);
	return buf;
}


void	test_naf(void)
{
	char	buf[BUFSIZE];

	printf("\tft_strcpy[");
	fun_tester_na(strcpy, ft_strcpy, make_buf(buf), "to copy");
	printf("]\n\tt_strlcat[");
	fun_tester_na(strlcat, ft_strlcat, make_buf(buf), "to copy", 12);
	printf("]\n");
	return ;
}
