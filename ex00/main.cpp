/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 02:19:49 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) 
{
		ClapTrap A = ClapTrap("Archer");
		ClapTrap B = ClapTrap("Berserker");
		ClapTrap C = A;

		C.set_name("Fake ClapTrap Archer"); 
		A.attack(B.get_name());
		B.attack(C.get_name());
		A.takeDamage(10);
		A.takeDamage(10);
		A.beRepaired(5);
		A.attack(B.get_name());

		for (int i = 0; i < 10; i ++)
			B.attack(A.get_name());

		return 0;
}