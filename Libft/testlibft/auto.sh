# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:16:40 by angagnie          #+#    #+#              #
#    Updated: 2015/12/08 21:00:14 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


save="$(PWD)"
#path="~/angagnie/libft/"
path=".."

echo $save, $path
cd $path
rm -f libft.a
ls -l ft_*.c | wc -l
make $1
cd $save
rm -f ./libft_tester
make $1
./libft_tester
