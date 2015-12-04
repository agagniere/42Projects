# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:16:40 by angagnie          #+#    #+#              #
#    Updated: 2015/12/04 10:57:52 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cd ../
ls -l ft_*.c | wc -l
#make re
#make clean
make
cd testlibft/
make
#make re > /dev/null
#make clean > /dev/null
./libft_tester
