/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:24:33 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/20 19:38:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PRINT(str) write(1, str, strlen(str))

typedef enum	e_player
{
	HUMAN,
	COMPUTER
}				t_player;

static int		max_index(int *b, int len)
{
	int ans;
	int i;

	i = 0;
	ans = 0;
	while (++i < len)
		if (b[i] > b[ans])
			ans = i;
	return (ans);
}

static void		print_board(int *map, int len)
{
	int row;
	int col;
	int max;

	row = -1;
	max = map[max_index(map, len)];
	PRINT("\033[0;33m");
	while (++row < len)
	{
		if (row == len - 1)
			PRINT("\033[1;33m");
		col = 0;
		while (col++ < max / 2 - map[row] / 2)
			write(1, " ", 1);
		col = 0;
		while (col++ < map[row])
			write(1, "|", 1);
		write(1, "\n", 1);
	}
	PRINT("\033[0m");
}

static int		min_index(int *b, int len)
{
	int ans;
	int i;

	i = 0;
	ans = 0;
	while (++i < len)
		if (b[i] < b[ans])
			ans = i;
	return (ans);
}

/*
** is_even : T(N) → N
** L’associativite et la commutativite de xor_int nous laisse libre pour l’ordre
** On rappelle que tout nombre non nul equivaut au True booleen
** @param : len ∈ N : la longueur de map
*/
static int		is_even(int *map, int len)
{
	int ans;

	ans = 0;
	while (len-- > 0)
	{
		ans ^= (*map++ + 3) % 4;
	}
	return (ans);
}

static int		human_turn(int *map, int len)
{
	char buf[1024];
	int n;
	int ans;

	n = 1;
	while (n > 0)
	{
		PRINT("Combien enlever d'allumettes ?\n");
		n = read(0, buf, 1024);
		if ((n == 2
			&& (ans = *buf - '0')
			&& 0 < ans && ans < 4
			&& ans <= map[len - 1]))
			n = 0;
	}
	printf("Vous enlevez %i allumettes\n", ans);
	return (ans);
}

static int		ai_turn(int *map, int len)
{
	int		b[3];
	int		i;

	i = 0;
	while (i < 3 && map[len - 1] > 0)
	{
		map[len - 1]--;
		b[i++] = is_even(map, len);
		printf("Retirer %i allumette amene la parite %i\n", i, b[i - 1]);
	}
	map[len - 1] += i;
	i = min_index(b, i) + 1;
	printf("Il faut donc en enlever %i\n", i);
	return (i);
}

int		main(int ac, char **av)
{
	int			map[] = {18, 9, 3, 1, 50, 50, 0};
	int			len = 4;
	t_player	player;

	player = COMPUTER;
	while (len > 0)
	{
		if (player == COMPUTER)
		{
			PRINT("\033[1J");
			PRINT("\033[H");
		}
		print_board(map, len);
		map[len - 1] -= (player == HUMAN ? human_turn(map, len) : ai_turn(map, len));
		if (map[len - 1] == 0)
			len--;
		player = !player;
	}
	PRINT("Et le gagnant est : ");
	if (player == COMPUTER)
	{
		PRINT("\033[1;31m");
		PRINT("HAL\n");
	}
	else
	{
		PRINT("\033[1;32m");
		PRINT("Vous !\n");
	}
	return (0);
}
