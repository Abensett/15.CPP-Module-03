/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/17 20:15:12 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
		ScavTrap A = ScavTrap("Archer");
		ScavTrap B = ScavTrap("Berserker");
		ScavTrap C = A;

		C.set_name("Chats");
		A.attack(B.get_name());
		B.attack(C.get_name());
		A.takeDamage(50);
		A.beRepaired(5);
		A.takeDamage(55);
		A.takeDamage(10);
		A.beRepaired(5);
		A.attack(B.get_name());
		A.guardGate();

		for (int i = 0; i < 50; i ++)
			B.attack(A.get_name());
		B.guardGate();
		return 0;
}
