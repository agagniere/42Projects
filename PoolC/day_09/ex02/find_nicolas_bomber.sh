# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_nicolas_bomber.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/16 21:49:46 by angagnie          #+#    #+#              #
#    Updated: 2015/07/16 21:49:54 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ $1 ]; then
	cat $1 | grep -i "Nicolas	Bomber" | awk '{print $(NF - 1)}' | grep -
	cat $1 | grep -i "Bomber	Nicolas" | awk '{printf$(NF - 1)}' | grep -
fi
