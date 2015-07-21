/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 22:17:31 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 23:00:02 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>
# include <stdlib.h>

int		ft_init_tab(int ***list, char **av);
int		test(int **tab, int y, int x, int nb);
int		draw(int **tab);
void	ft_backtrack(int **tab, int pos, int *ptr);
int		**ft_create_table(void);
int		is_valid(char **av);
int		ft_backtrack_bis(int **tab, int pos);

#endif
