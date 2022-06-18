/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/18 17:16:05 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
		DiamondTrap A = DiamondTrap("Archer");
		DiamondTrap B = DiamondTrap("Berserker");
		DiamondTrap C("Chaton");

		A.attack(B.get_name());
		B.attack(C.get_name());
		A.takeDamage(50);
		A.beRepaired(5);
		A.takeDamage(105);
		A.takeDamage(10);
		A.beRepaired(5);
		A.attack(B.get_name());
		C.highFivesGuys();
		C.guardGate();
		C.whoAmI();
	//	for (int i = 0; i < 100; i ++)
	//		B.attack(A.get_name());

		return 0;
}
