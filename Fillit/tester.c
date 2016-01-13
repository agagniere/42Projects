/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:08:53 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 11:49:34 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <time.h>
#include <stdlib.h>

#define	NEW_PNT ((t_pnt){0,0})
#define	NEW_DIM ((t_dim){0,0})
#define	NEW_TET ((t_tet){{NEW_PNT,NEW_PNT,NEW_PNT,NEW_PNT},NEW_PNT,NEW_DIM})

void	get_tetrimino(int i, t_tet *where)
{
	t_tet ans;

	printf("Piece #%i\n", i);

	switch (i) {
	case 0 :
		ans = (t_tet){(t_pnt){0,0}, (t_pnt){0,1}, (t_pnt){0,2}, (t_pnt){0,3}, NEW_PNT, (t_dim){1,4}};
		break;
	case 1 :
		ans = (t_tet){(t_pnt){0,0}, (t_pnt){1,0}, (t_pnt){2,0}, (t_pnt){3,0}, NEW_PNT, (t_dim){4,1}};
		break;
	case 2 :
		ans = (t_tet){(t_pnt){0,0}, (t_pnt){0,1}, (t_pnt){1,0}, (t_pnt){1,1}, NEW_PNT, (t_dim){2,2}};
		break;
	case 3 :
		ans = (t_tet){(t_pnt){0,1}, (t_pnt){1,1}, (t_pnt){1,0}, (t_pnt){2,1}, NEW_PNT, (t_dim){3,2}};
		break;
	case 4 :
		ans = (t_tet){(t_pnt){0,0}, (t_pnt){1,0}, (t_pnt){2,0}, (t_pnt){1,1}, NEW_PNT, (t_dim){3,2}};
		break;
	case 5 :
		ans = (t_tet){(t_pnt){0,0}, (t_pnt){0,1}, (t_pnt){0,2}, (t_pnt){1,1}, NEW_PNT, (t_dim){2,3}};
		break;
	case 6 :
		ans = (t_tet){(t_pnt){1,0}, (t_pnt){1,1}, (t_pnt){1,2}, (t_pnt){0,1}, NEW_PNT, (t_dim){2,3}};
		break;
	}
	ft_print_memory(&ans, sizeof(ans));
	memcpy(where, &ans, sizeof(ans));
}

int main(int ac, char **av)
{
	int		n = ac > 1 ? atoi(av[1]) : 4;
	t_tet	**arg1;
	int		i = n;

	arg1 = (t_tet **)malloc(sizeof(t_tet *) * n);
	while (i-- > 0)
	{
		arg1[i] = (t_tet *)malloc(sizeof(t_tet));
		get_tetrimino(i % 7, arg1[i]);
	}
	printf("Launching\n");
	solve(arg1, n);
	return (0);
}
