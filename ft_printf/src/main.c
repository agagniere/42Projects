/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/10 16:19:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <string.h>

#define TEST(FMT, ARGS)													\
	pf = asprintf(&pf_dst,FMT,ARGS);									\
	ft = ft_asprintf(&ft_dst,FMT,ARGS);									\
	if (ft != pf)														\
		dprintf(2, "Fail : return value (%i vs %i)\n", pf, ft);			\
	if (strcmp(ft_dst, pf_dst))									\
		dprintf(2, "%sFail : strings differ\n|%s| (Real) vs\n|%s|.\n%s", \
				"\e[1;31m", pf_dst, ft_dst, "\e[0m");					\
	else																\
		dprintf(1, "\e[1;32m|%s|\e[0m\n", ft_dst);

int		main(int ac, char **av)
{
	char	*pf_dst;
	char	*ft_dst;
	int		pf;
	int		ft;

	TEST("1-Simple String.", 0);
	TEST("2-Stringception _%s_", "Hello World");
	TEST("3-Stringception _%20s_", "Hello World");
	TEST("4-Stringception _%-20s_", "Hello World");
	TEST("5-Stringception _%20.5s_", "Hello World");
	TEST("6-Stringception _%-20.5s_", "Hello World");
	TEST("7-Stringception _%020s_", "Hello World");
	TEST("8-Stringception _%0-.20s_", "Hello World");
	TEST("9-Stringception _%20s_", "Hello World");
	TEST("A-Stringception _%20s_", "Hello World");
	TEST("B-Stringception _%20.s_", "Hello World");
	TEST("C-Stringception _%-#20s_", "Hello World");
	TEST("D-Integer _%hhi_", -61234);
	TEST("E-Integer _%hhu_", -61234);
	TEST("F-Integer _%hhhi_", -61234);
	TEST("G-Integer _%hhhu_", -61234);
	TEST("H-Integer _%hhhhi_", -61234);
	TEST("I-Integer _%hhhhu_", -61234);
	TEST("J-Integer _%hhhx_", -61234);
	TEST("K-Integer _%lX_", 0xDEADBEEF);
	TEST("L-Pointer _%p_", &pf);
	TEST("M-Pointer _%hhp_", &pf);
	TEST("N-Pointer _%p_", &pf);
	TEST("O-Pointer _%hhp_", &pf);
	TEST("P-Combo _%20i_", -'*');
	TEST("Q-Combo _%20.10i_", -'*');
	TEST("R-Combo _%.10i_", -'*');
	TEST("S-Combo _%020i_", -'*');
	TEST("T-Combo _%#20.10x_", '*');
	TEST("U-Combo _%-20i_", -'*');
	TEST("V-Combo _%-20.10i_", -'*');
	TEST("W-Combo _%-.10i_", -'*');
	TEST("X-Combo _%-020i_", -'*');
	TEST("Y-Combo _%-#20.10x_", '*');
	TEST("Z-Combo _%S_", L"Helloλ\0\0\0");
	(void)ac;
	(void)av;
	return (0);
}
