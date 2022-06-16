/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 02:47:58 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

// Default Constructor
ClapTrap::ClapTrap(void) : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) {
    cout << "ClapTrap constructor was called" << endl;
}
// Destructor
ClapTrap::~ClapTrap(void) {
    cout << "ClapTrap " << _name << " was deconstructed" << endl;
}
// Constructor with name
ClapTrap::ClapTrap(string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    cout << "ClapTrap " << _name << " was constructed" << endl;
}
// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &claptrap) {
    *this = claptrap;
}
// Copy Assignment Operator
ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
    cout << "ClapTrap " << claptrap._name << " was copied" << endl;

    if (this != &claptrap) {
        _name = claptrap._name;
        _hit_points = claptrap._hit_points;
        _energy_points = claptrap._energy_points;
        _attack_damage = claptrap._attack_damage;
    }

    return *this;
}

// Getter for name
string ClapTrap::get_name(void) const {
    return _name;
}
// Setter for name
void ClapTrap::set_name(string name) {
    _name = name;
}
// Attack function
void ClapTrap::attack(const string &target) {
    if (_energy_points && _hit_points) {                                                       // If energy points are greater than 0
        --_energy_points;
        cout << "ClapTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << endl;      
    } else {                                                                   // If energy points are 0 
        cout << "ClapTrap " << _name << " is either dead or too tired." << endl;
    }
}
// Take Damage function
void ClapTrap::takeDamage(unsigned int amount) {                   
    if (!_hit_points) {                                                         // If hit points are 0 already dead
        cout << "ClapTrap " << _name << " is already dead" << endl;         
    } else {                                                                    // If hit points are greater than 0
        _hit_points -= amount;

        if (_hit_points < 0)
            _hit_points = 0;

        cout << "ClapTrap " << _name << " took " << amount << " damage" << endl;
        cout << "ClapTrap " << _name << " is at " << _hit_points << " HP" << endl;

        if (!_hit_points)                                                           // If hit points are 0 dead
            cout << "ClapTrap " << _name << " died" << endl;
    }
}
// Be Repaired function
void ClapTrap::beRepaired(unsigned int amount) {                                

    if (_energy_points && _hit_points) {                                                          //if energy points are greater than 0
        --_energy_points;
        _hit_points += amount;                                                              //if energy points are 0
        cout << "ClapTrap " << _name << " repaired " << amount << " HP" << endl;
        cout << "ClapTrap " << _name << " is at " << _hit_points << " HP" << endl;

    } else {          
        cout << "ClapTrap " << _name << " is either dead or too tired." << endl;
    }
   

}