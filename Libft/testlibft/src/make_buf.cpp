// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   make_buf.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/30 17:24:47 by angagnie          #+#    #+#             //
//   Updated: 2015/12/08 17:38:44 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

char	*clear_buf(char *buf, char const *tocopy)
{
	bzero(buf, BUFSIZE);
	strcpy(buf, tocopy);
	return (buf);
}
