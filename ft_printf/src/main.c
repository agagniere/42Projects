/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/22 12:53:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <string.h>

#define TEST(FMT,...)													\
	pf = asprintf(&pf_dst,FMT,__VA_ARGS__);								\
	ft = ft_asprintf(&ft_dst,FMT,__VA_ARGS__);							\
	if (ft != pf)														\
		dprintf(2, "Fail : return value (%i vs %i)\n", pf, ft);			\
	if (pf >= 0) {														\
		if (strcmp(ft_dst, pf_dst))										\
			dprintf(2, "%sFail : strings differ\n|%s| (Real) vs\n|%s|\n%s", \
					"\e[1;31m", pf_dst, ft_dst, "\e[0m");				\
		else															\
			dprintf(1, "\e[1;32m|%s|\e[0m\n", ft_dst);					\
	}

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
	TEST("J-Integer [p] _%#.10hhhx_", -61234);
	TEST("K-Integer _%lX_", 0xDEADBEEF);
	TEST("L-Pointer _%p_", &pf);
	TEST("M-Pointer _%hhp_", &pf);
	TEST("N-Pointer _%p_", &pf);
	TEST("O-Pointer _%hhp_", &pf);
	TEST("P-Combo _%20i_", -'*');
	TEST("Q-Combo [lp]_%20.10i_", -'*');
	TEST("R-Combo [p]_%.10i_", -'*');
	TEST("S-Combo [l]_%020i_", -'*');
	TEST("T-Combo [lp]_%#20.10x_", '*');
	TEST("U-Combo _%-20i_", -'*');
	TEST("V-Combo _%-20.10i_", -'*');
	TEST("W-Combo _%-.10i_", -'*');
	TEST("X-Combo _%-020i_", -'*');
	TEST("Y-Combo _%-#20.10x_", '*');
	TEST("Z-Combo _%s_", "Helloλ");
	TEST("10-NULL string _%s_", NULL);
	TEST("11-NULL string _%4s_", NULL);
	TEST("12-NULL string _%.4s_", NULL);
	TEST("13-NULL string _%S_", NULL);
	TEST("14-NULL string _%4S_", NULL);
	TEST("15-NULL string _%l.4s_", NULL);
	TEST("16-Bonus _%-2147483648.99h+08h#.04i_", '*');
	TEST("17-Nothing _%20.10",0);
	TEST("18-Nothing _%20.10_",0);
	TEST("19-Nothing _%20.10&_",0);
	TEST("1A-Nothing _%20.10@_",0);
	TEST("1B-Nothing _%20.10`_",0);
	TEST("1C-Nothing _%20.10%_",0);
	TEST("1D-Number _%015#X_", 0xDEADBEEF);
	TEST("1E-Zero _%+i_", 0);
	TEST("1F-Zero _%0+i_", 0);
	TEST("1G-Zero _%.0+i_", 0);
	TEST("1H-Zero _%.0+u_", 0);
	TEST("1I-Zero _%10.0i_", 0);
	TEST("1J-Zero _%10.0+u_", 0);
	TEST("1K-Zero _%-10.0+i_", 0);
	TEST("1L-Advanced _%i_%10i_%.5i_%10.5i_%010i_",-42,-42,-42,-42,-42);
	TEST("1M-Advanced _%u_%10u_%.5u_%10.5u_%010u_",-42,-42,-42,-42,-42);
	TEST("1N-Advanced _%#x_%10#x_%.5#x_%10.5#x_%010#x_",-42,-42,-42,-42,-42);
	TEST("1O-Advanced _%#X_%10#X_%.5#X_%10.5#X_%010#X_",-42,-42,-42,-42,-42);
	TEST("1P-Advanced _%#o_%10#o_%.5#o_%10.5#o_%010#o_",-42,-42,-42,-42,-42);
	TEST("%s", "The End");
	(void)ac;
	(void)av;
	return (0);
}
