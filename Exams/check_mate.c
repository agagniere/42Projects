/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <angagnie@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:07:23 by sid               #+#    #+#             */
/*   Updated: 2019/05/30 17:52:32 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _point point;
typedef struct _board board;

struct _point
{
    int x;
    int y;
};

struct _board
{
    int    width;
    int    height;
    char** board;
};

#define POINT_new(X,Y) (point){X,Y}

#define BOARD_new(W,H,B) (board){W,H,B}

/*
** Returns the piece attackable
** from this position with this direction
**
** ..K..
** ..P..
** .....
** ..^..
**
** From (2,3), with direction (0,-1)
** the returned value will be 'P'
**
** If no piece is capturable this way, '|' (Wall)
** is returned
*/
char ray(const board* board,
         point pos,
         point dir)
{
    while ((pos.x > 0 || dir.x >= 0)
           && (pos.x < board->width - 1 || dir.x <= 0)
           && (pos.y > 0 || dir.y >= 0)
           && (pos.y < board->height - 1 || dir.y <= 0))
    {
        pos.x += dir.x;
        pos.y += dir.y;
        if (strchr("PBRQK", board->board[pos.y][pos.x]) != NULL)
            return (board->board[pos.y][pos.x]);
    }
    return ('|');
}

/*
** Returns true if the king can be captured
** by this piece
*/
bool is_checking_king(const board* board,
                      point pos)
{
    char piece = board->board[pos.y][pos.x];
    int  i = 9;

    if (piece == 'P' && pos.y > 0)
        return ((pos.x > 0 && board->board[pos.y-1][pos.x-1] == 'K')
				|| (pos.x < board->width - 1 && board->board[pos.y-1][pos.x+1] == 'K'));
    while (i --> 0)
    {
        point d = POINT_new((i % 3) - 1, (i / 3) - 1);
        if (((d.x && d.y && piece != 'R')
             || (!d.x != !d.y && piece != 'B'))
            && (ray(board, pos, d) == 'K'))
            return (true);
    }
    return (false);
}

bool is_king_incheck(const board* board)
{
    point p = POINT_new(0, board->height);

    while (p.y --> 0)
    {
        p.x = board->width;
        while (p.x --> 0)
            if ((strchr("PBRQ", board->board[p.y][p.x]) != NULL)
                && (is_checking_king(board, p)))
                return (true);
    }
    return (false);
}

int  main(int ac, char** av)
{
	if (ac > 1)
	{
		ac--;
		av++;
		board game = BOARD_new(strlen(*av), ac, av);
		printf(is_king_incheck(&game) == true ? "Success" : "Fail");
	}
	printf("\n");
    return (0);
}
