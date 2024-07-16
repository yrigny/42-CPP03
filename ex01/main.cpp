/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:53:52 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 18:25:24 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#define GREEN "\033[1;32m"
#define NONE "\033[0m"

void	getStat(ScavTrap& obj) {
	std::cout << GREEN "Status: " NONE << obj.getName() << " has " << obj.getHitPoints() << " hit points, " << obj.getEnergyPoints() << " energy points, " << obj.getAttackDamage() << " attack damage, " << "gate keeper mode = " << obj.getMode()  << std::endl;
}

int main(void) {
	std::cout << "Construction order:" << std::endl;
	ScavTrap	a("a");
	ScavTrap	b("b");

	std::cout << std::endl << "Test for ScavTrap's method guardGate():" << std::endl;
	getStat(a);
	a.guardGate();
	getStat(a);
	a.guardGate();
	getStat(a);

	std::cout << std::endl << "Test for methods inherited from class ClapTrap:" << std::endl;
	getStat(a);
	getStat(b);

	std::cout << std::endl << "case: normal attack() and normal takeDamage()" << std::endl;
	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	getStat(a);
	getStat(b);
	b.attack("a");
	a.takeDamage(b.getAttackDamage());
	getStat(a);
	getStat(b);

	std::cout << std::endl << "case: normal beRepaired()" << std::endl;
	a.beRepaired(10);
	b.beRepaired(10);
	getStat(a);
	getStat(b);

	std::cout << std::endl << "case: takeDamage() when damage received > HP" << std::endl;
	std::cout << "setting b's attack damage to 100..." << std::endl;
	b.setAttackDamage(100);
	b.attack("a");
    a.takeDamage(b.getAttackDamage());
	getStat(a);
	getStat(b);

	std::cout << std::endl << "case: beRepaired() when hit points = 0" << std::endl;
	a.beRepaired(10);
	getStat(a);

	std::cout << std::endl << "case: beRepaired() when energy points = 0" << std::endl;
	std::cout << "setting b's energy points to 0..." << std::endl;
	b.setEnergyPoints(-b.getEnergyPoints());
	b.beRepaired(10);
	getStat(b);

	std::cout << std::endl << "Destruction order:" << std::endl;
	return 0;
}
