/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/18 17:14:52 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP_
#define FragTrap_HPP_

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
 public:
    FragTrap(void);
    explicit FragTrap(string name);
    FragTrap(const FragTrap &FragTrap);
    FragTrap &operator=(const FragTrap &FragTrap);
    ~FragTrap(void);

    void set_name(string name);
    void attack(const string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys(void) const;
};

#endif
