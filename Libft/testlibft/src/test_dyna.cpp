// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_dyna.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/08 12:23:30 by angagnie          #+#    #+#             //
//   Updated: 2015/12/08 13:38:44 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

void	test_dyna()
{
	t_dyna	vector[1];
	int		i = 0;
	int		s, r[10];
	char	c[26];

	vector[0] = ft_dyna_new(sizeof(int));
	while ((s = i++) < 10)
	{
		r[s] = i * i;
		ft_dyna_append(vector, r + s, 1);
	}
	printf("dyna_A[");
	MARK(vector->chunck_size == 4, s, "wrong chunck size");
	MARK(vector->chunck_count == 10, c, "wrong chunck count");
	MARK(vector->chunck_max == 16, m, vector->chunck_max);
	MARK(!memcmp(vector->data, r, 40), d, "wrong data");
	printf("%s]\n", END);

	ft_dyna_del(vector);
	vector[0] = ft_dyna_new(sizeof(char));
	i = 0;
	while ((s = i++) < 26)
	{
		c[s] = 65 + s;
		ft_dyna_append(vector, c + s, 1);
	}

	printf("dyna_B[");
	MARK(vector->chunck_size == 1, s, "wrong chunck size");
	MARK(vector->chunck_count == 26, c, "wrong chunck count");
	MARK(vector->chunck_max == 32, m, vector->chunck_max);
	MARK(!memcmp(vector->data, c, 26), d, "wrong data");
	printf("%s]\n", END);
}
