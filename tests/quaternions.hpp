/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:11:42 by sid               #+#    #+#             */
/*   Updated: 2015/12/18 00:12:07 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
typedef union	s_quater
{
	double		raw[4];
	struct
	{
		double		s;
		union
		{
			double	v[3];
			struct
			{
				double x;
				double y;
				double w;
			};
		};
	};
}				t_quater;


class Quaternion<T>
{
private :
	t_quater	value;

public :
	Quaternion();
	Quaternion(T a);
	t_quater	getConjugate();
}
