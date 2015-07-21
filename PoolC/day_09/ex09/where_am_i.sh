# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    where_am_i.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/17 07:07:11 by angagnie          #+#    #+#              #
#    Updated: 2015/07/17 07:07:12 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifconfig | grep 'inet ' | cut -d ' ' -f 2 | wc -l | tr -d ' ' > tmp
echo '0' > tmp2
if cmp -s tmp tmp2
then
	echo 'Je suis perdu!'
else
	ifconfig | grep 'inet ' | cut -d ' ' -f 2
fi
rm tmp tmp2
