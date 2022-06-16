/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 02:43:10 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
using std::cout;
using std::endl;

DiamondTrap::DiamondTrap(void) : ClapTrap() {
    cout <<  "DiamondTrap constructor was called." << endl;
}

DiamondTrap::DiamondTrap(string name) : ClapTrap(name) {                //inherits from ClapTrap constructor differentl initialisation

    cout << "DiamondTrap " << _name << " was constructed" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap) {
    *this = DiamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap) {
    cout << "DiamondTrap " << DiamondTrap._name << " was copied" << endl;

    if (this != &DiamondTrap) {
        _name = DiamondTrap._name;
        _hit_points = DiamondTrap._hit_points;
        _energy_points = DiamondTrap._energy_points;
        _attack_damage = DiamondTrap._attack_damage;
    }

    return *this;
}

DiamondTrap::~DiamondTrap(void) {
    cout << "DiamondTrap " << _name << " was deconstructed" << endl;
}

void DiamondTrap::set_name(string name) {
    cout << "DiamondTrap " << _name << "'s copy is now DiamondTrap " << name << endl;
    _name = name;
}

void DiamondTrap::attack(const string &target) {
    if (_energy_points && _hit_points) {
        --_energy_points;
        cout << "DiamondTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << endl;
    } else {
        cout << "DiamondTrap " << _name << " is dead or too tired." << endl;
    }
}

void DiamondTrap::takeDamage(unsigned int amount) {
    if (!_hit_points) {
        cout << "DiamondTrap " << _name << " is already dead" << endl;
    } else {
        _hit_points -= amount;

        if (_hit_points < 0)
            _hit_points = 0;

        cout << "DiamondTrap " << _name << " took " << amount << " damage" << endl;
        cout << "DiamondTrap " << _name << " is at " << _hit_points << " HP" << endl;

        if (!_hit_points)
            cout << "DiamondTrap " << _name << " died" << endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount) {

    if (_energy_points && _hit_points) {
        --_energy_points;
        _hit_points += amount;
        cout << "DiamondTrap " << _name << " healed " << amount << " HP" << endl;
        cout << "DiamondTrap " << _name << " is at " << _hit_points << " HP" << endl;
    } else {
        cout << "DiamondTrap " << _name << " is dead or too tired." << endl;
    }
}

void DiamondTrap::whoAmI(void) const {
    cout << "My DiamondTrap name is " << _name << endl;
    cout << "My ClapTrap name is " << this->ClapTrap::get_name() << endl;
}