/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 02:55:37 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::string;

class DiamondTrap: public ScavTrap, public FragTrap {
 public:
    DiamondTrap(void);
    ~DiamondTrap(void);

    explicit DiamondTrap(string name);
    DiamondTrap(const DiamondTrap &diamondtrap);
    DiamondTrap &operator=(const DiamondTrap &diamondtrap);

    void set_name(string name);
    void attack(const string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void whoAmI(void) const;
 private:
    string _name;
};

#endif