# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    couilleCreator.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/16 21:32:24 by angagnie          #+#    #+#              #
#    Updated: 2015/07/17 07:59:08 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COUILLE="mesCouilles.sh"
export COUILLE

find . -type f -exec sh -c "
echo -n 'echo \\\"' >> $COUILLE
cat $0 | sed 's/angagnie/\$USER/g' >> $COUILLE
echo \\\" >> $COUILLE
" {} \;
