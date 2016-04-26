/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol_code.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:36:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/26 12:55:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOL_CODE_H
# define LOL_CODE_H

# define CAN_HAS(P) #include <P>
# define HAI(V) int main(void) {
# define KTHXBYE }

# define BTW / ## /
# define OBTW / ## *
# define TlDR * ## /

# define VISIBLE(M) printf(M);
# define INVISIBLE(M) dprintf(2, M);

# define I_HAS_A(V) int V = 0;
# define UP(V,HM) V += HM;

# define IM_IN_YR_LOOP while (1) {
# define IM_OUTTA_YR_LOOP }
# define KTHX break;
# define GTFO break;

# define O_RLY(E) if (E)
# define YA_RLY {
# define NO_WAI } else {
# define OIC }

# define WTF(V) switch (V) {
# define OMG(C) case C :
# define OMGWTF default :

#endif
