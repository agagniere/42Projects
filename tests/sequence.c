/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:56:44 by angagnie          #+#    #+#             */
/*   Updated: 2017/05/16 22:05:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
** Terminal recursion training
*/


/*
** 1 : Guess the next element of the following sequences
** 2 : Express the recursive relation
** 3 : Code a terminal recursive function
*/

/*
** A :	5	7	12	19	31	50
** A':	4	7	15	29	59	117
** -
** B :	4	8	16	32	64	128
** B':	4	12	36	108
** -
** C :	2	5	9	14	20	27
** -
** D :	60	54	56	50	52	46
** -
** E :	97	102	92	107	87
** -
** F :	4	5	10	50	400	3500
*/

/*
** A : Fibonacci sequence (non-canonical)
** -
** A(i) = match i with
** | 0 -> u0
** | 1 -> u1
** | _ -> A(i-1) + M * A(i-2);
** -
** Matrices would allow a log(i) complexity, but at a greater cost per operation
*/

static int16_t		_A(int16_t u0, int16_t u1, int16_t m, uint8_t i)
{
	if (i == 0)
		return (u0);
	return _A(u1, m * u0 + u1, m, i - 1);
}

int16_t				A1(uint8_t i) {return _A(5, 7, 1, i);}
int16_t				A2(uint8_t i) {return _A(4, 7, 2, i);}

/*
** B : Multiply by M^i
** -
** B(i) = match i with
** | 0 -> u0
** | _ -> M * B(i-1)
** -
** Actually multiplying by M^i would allow a log(i) complexity
*/

static int16_t		_B(int16_t u0, int16_t m, uint8_t i)
{
	if (i == 0)
		return (u0);
	return _B(m * u0, m, i - 1);
}

int16_t				B1(uint8_t i) {return _B(4, 2, i);}
int16_t				B2(uint8_t i) {return _B(4, 3, i);}

/*
** C : a + \sum_{k=0}^{k<i} (b-a)+k
** -
** ib - (i-1)a + _C(0,0,i)
** -
** C(i) = match i with
** | 0 -> u0
** | 1 -> u1
** | _ -> 2 * C(i-2) - C(i-1) + 1
*/

static int16_t		_C(int16_t u0, int16_t u1, uint8_t i)
{
	if (i == 0)
		return (u0);
	else
		return _C(u1, 2 * u1 - u0 + 1, i - 1);
}

int16_t				C(uint8_t i){return _C(2, 5, i);}

/*
** D : a + b * i//2 + c * (i+1)//2
** -
** D(i) = match i with
** | 0 -> u0
** | n where (n % 2 == 1) -> D(i-1) + a1
** | _ -> D(i-1) + a2
** -
** Here the general formula is better.
*/

static int16_t		_D(int16_t u0, int16_t a1, int16_t a2, uint8_t i)
{
	if (i == 0)
		return (u0);
	return _D(u0 + (i % 2 ? a1 : a2), a1, a2, i - 1);
}

int16_t				D1(uint8_t i) {return _D(60, -6, 2, i);}
int16_t				D2(uint8_t i) {return 60 - 6 * ((i+1)/2) + 2 * (i/2);}

int		E(int i)
{
	if (i == 0)
		return (97);
	else
		return (E(i-1) + 5 * (i) * (i % 2 ? 1 : -1));
}

int		F(int i)
{
	if (i == 0)
		return (4);
	else if (i == 1)
		return (5);
	else
		return (10 * (F(i-1) - F(i-2)));
}

int	 main(int ac, char **av)
{
	int16_t (*f[])(uint8_t) = {A1, A2, B1, B2, C, D1, D2};
	int	i,
		j;

	for (j = 0 ; j < 7 ; j++)
	{
		for (i = 0 ; i < 8 ; i++)
			printf("%i ", f[j](i));
		printf("\n");
	}
	return (0);
}
