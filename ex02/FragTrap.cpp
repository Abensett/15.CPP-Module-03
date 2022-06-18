/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/18 16:55:14 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
using std::cout;
using std::endl;

FragTrap::FragTrap(void) : ClapTrap::ClapTrap() {
    cout <<  "FragTrap constructor was called." << endl;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
}

FragTrap::FragTrap(string name) : ClapTrap::ClapTrap(name) {                //inherits from ClapTrap constructor differentl initialisation
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    cout << "FragTrap " << _name << " was constructed" << endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap) {
    cout << "FragTrap " << FragTrap._name << " was copied" << endl;
    *this = FragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap) {
    cout << "FragTrap " << FragTrap._name << " was assigned" << endl;

    if (this != &FragTrap) {
        _name = FragTrap._name;
        _hit_points = FragTrap._hit_points;
        _energy_points = FragTrap._energy_points;
        _attack_damage = FragTrap._attack_damage;
    }

    return *this;
}

FragTrap::~FragTrap(void) {
    cout << "FragTrap " << _name << " was deconstructed" << endl;
}

void FragTrap::set_name(string name) {
    cout << "FragTrap " << _name << "'s copy is now FragTrap " << name << endl;
    _name = name;
}

void FragTrap::attack(const string &target) {
    if (_energy_points && _hit_points) {
        --_energy_points;
        cout << "FragTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << endl;
    } else {
        cout << "FragTrap " << _name << " is dead or too tired." << endl;
    }
}

void FragTrap::takeDamage(unsigned int amount) {
    if (!_hit_points) {
        cout << "FragTrap " << _name << " is already dead" << endl;
    } else {
        _hit_points -= amount;

        if (_hit_points < 0)
            _hit_points = 0;

        cout << "FragTrap " << _name << " took " << amount << " damage" << endl;
        cout << "FragTrap " << _name << " is at " << _hit_points << " HP" << endl;

        if (!_hit_points)
            cout << "FragTrap " << _name << " died" << endl;
    }
}

void FragTrap::beRepaired(unsigned int amount) {

    if (_energy_points && _hit_points) {
        --_energy_points;
        _hit_points += amount;
        cout << "FragTrap " << _name << " healed " << amount << " HP" << endl;
        cout << "FragTrap " << _name << " is at " << _hit_points << " HP" << endl;
    } else {
        cout << "FragTrap " << _name << " is dead or too tired." << endl;
    }
}

void FragTrap::highFivesGuys(void) const {
     if (_energy_points && _hit_points)
        cout << "FragTrap " << _name << " is asking for HighFive." << endl;
     else
         cout << "FragTrap " << _name << " is dead or too tired." << endl;
}
