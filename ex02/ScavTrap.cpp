/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/17 20:11:25 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
using std::cout;
using std::endl;

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap() {
    cout <<  "ScavTrap constructor was called." << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap::ClapTrap(name) {                //inherits from ClapTrap constructor differentl initialisation
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    cout << "ScavTrap " << _name << " was constructed" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) {
    cout << "ScavTrap " << scavtrap._name << " was copied" << endl;
    *this = scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
    cout << "ScavTrap " << scavtrap._name << " was assigned" << endl;

    if (this != &scavtrap) {
        _name = scavtrap._name;
        _hit_points = scavtrap._hit_points;
        _energy_points = scavtrap._energy_points;
        _attack_damage = scavtrap._attack_damage;
    }

    return *this;
}

ScavTrap::~ScavTrap(void) {
    cout << "ScavTrap " << _name << " was deconstructed" << endl;
}

void ScavTrap::set_name(string name) {
    cout << "ScavTrap " << _name << "'s copy is now ScavTrap " << name << endl;
    _name = name;
}

void ScavTrap::attack(const string &target) {
    if (_energy_points && _hit_points) {
        --_energy_points;
        cout << "ScavTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << endl;
    } else {
        cout << "ScavTrap " << _name << " is dead or too tired." << endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (!_hit_points) {
        cout << "ScavTrap " << _name << " is already dead" << endl;
    } else {
        _hit_points -= amount;

        if (_hit_points < 0)
            _hit_points = 0;

        cout << "ScavTrap " << _name << " took " << amount << " damage" << endl;
        cout << "ScavTrap " << _name << " is at " << _hit_points << " HP" << endl;

        if (!_hit_points)
            cout << "ScavTrap " << _name << " died" << endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount) {

    if (_energy_points && _hit_points) {
        --_energy_points;
        cout << "ScavTrap " << _name << " healed " << amount << " HP" << endl;
        cout << "ScavTrap " << _name << " is at " << _hit_points << " HP" << endl;
        _hit_points += amount;
    } else {
        cout << "ScavTrap " << _name << " is dead or too tired." << endl;
    }
}

void ScavTrap::guardGate(void) const {
    if (_energy_points && _hit_points)
        cout << "ScavTrap " << _name << " is in Gatekeeper Mode" << endl;
    else
         cout << "ScavTrap " << _name << " is dead or too tired." << endl;
}
