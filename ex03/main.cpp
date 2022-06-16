/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 03:03:42 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) 
{
		DiamondTrap A = DiamondTrap("Archer");
		DiamondTrap B = DiamondTrap("Berserker");
		DiamondTrap C = A;

		C.set_name("C");
		A.attack(B.get_name());
		B.attack(C.get_name());
		A.takeDamage(50);
		A.beRepaired(5);
		A.takeDamage(105);
		A.takeDamage(10);
		A.beRepaired(5);
		A.attack(B.get_name());

	//	for (int i = 0; i < 100; i ++)
	//		B.attack(A.get_name());

		return 0;
}