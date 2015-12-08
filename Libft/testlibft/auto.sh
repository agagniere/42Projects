# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:16:40 by angagnie          #+#    #+#              #
#    Updated: 2015/12/08 17:17:57 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


save="$(PWD)"
#path="~/angagnie/libft/"
path=".."

echo $save, $path
cd $path
rm -f libft.a
ls -l ft_*.c | wc -l
make
cd $save
rm -f ./libft_tester
make
./libft_tester
