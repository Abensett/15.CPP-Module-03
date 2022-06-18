/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/18 16:49:45 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>
#include <string>

using std::string;

class ClapTrap
{
 	public:
		ClapTrap(void);
		~ClapTrap(void);
		explicit ClapTrap(string name);							// explicit retire la propriete de conversion d'un constructeur
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator=(const ClapTrap &claptrap);

		string 	get_name(void) const;
		void	set_name(string name);
		void 	attack(const string &target);
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);

 private:
    string _name;
    int 	_hit_points;
    int 	_energy_points;
    int 	_attack_damage;
};

#endif
