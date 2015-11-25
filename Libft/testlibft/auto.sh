# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:16:40 by angagnie          #+#    #+#              #
#    Updated: 2015/11/25 17:23:14 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cd ../
ls -l ft_*.c | wc -l
make re
make clean
cd testlibft/
make re > /dev/null
make clean > /dev/null
./test_libft
