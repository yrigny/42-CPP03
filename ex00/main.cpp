/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:08:05 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/15 17:04:01 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	getStat(ClapTrap& obj) {
	std::cout << obj.getName() << " has " << obj.getHitPoints() << " hit points, " << obj.getEnergyPoints() << " energy points, " << obj.getAttackDamage() << " attack damage." << std::endl;
}

int main(void) {
    ClapTrap    a("a");
    ClapTrap    b("b");

	std::cout << std::endl << "Test: round 1" << std::endl;
    // set attack damage for a and b
    a.setAttackDamage(3);
    b.setAttackDamage(5);
	getStat(a);
	getStat(b);
    // a attacks b
    a.attack("b");
    b.takeDamage(a.getAttackDamage());
	getStat(a);
	getStat(b);
    // b attacks a
    b.attack("a");
    a.takeDamage(b.getAttackDamage());
	getStat(a);
	getStat(b);
	// a and b repair themselves
	a.beRepaired(4);
	b.beRepaired(4);
	getStat(a);
	getStat(b);

	std::cout << std::endl << "Test: round 2" << std::endl;
    // set new attack damage for a and b
    a.setAttackDamage(6);
	b.setAttackDamage(10);
	getStat(a);
	getStat(b);
	// a attacks b
	a.attack("b");
    b.takeDamage(a.getAttackDamage());
	getStat(a);
	getStat(b);
	// b attacks a
	b.attack("a");
    a.takeDamage(b.getAttackDamage());
	getStat(a);
	getStat(b);
	// a and b repair themselves
	a.beRepaired(5);
	b.beRepaired(5);
	getStat(a);
	getStat(b);

	// destructor message
	std::cout << std::endl;

	return 0;
}
