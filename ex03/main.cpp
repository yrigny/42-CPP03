/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:00:52 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 19:51:11 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#define GREEN "\033[1;32m"
#define NONE "\033[0m"

void	getStat(DiamondTrap& obj) {
	std::cout << GREEN "Status: " NONE << obj.getName() << " has " << obj.getHitPoints() << " hit points, " << obj.getEnergyPoints() << " energy points, " << obj.getAttackDamage() << " attack damage, " << "gate keeper mode = " << obj.getMode()  << std::endl;
}

int main(void) {
	std::cout << "Construction order:" << std::endl;
	DiamondTrap	a("a");
	DiamondTrap	b("b");

	std::cout << std::endl << "Test for copy constructor:" << std::endl;
	DiamondTrap	c(a);

	std::cout << std::endl << "Test for copy assignment operator:" << std::endl;
	DiamondTrap	d = b;

	std::cout << std::endl << "Test for DiamondTrap's method whoAmI():" << std::endl;
	c.whoAmI();
	d.whoAmI();

	std::cout << std::endl << "Test for method guardGate() inherited from ScavTrap:" << std::endl;
	getStat(c);
	c.guardGate();
	getStat(c);
	c.guardGate();
	getStat(c);

	std::cout << std::endl << "Test for method highFiveGuys() inherited from FragTrap:" << std::endl;
	d.highFiveGuys();

	std::cout << std::endl << "Test for methods inherited from ClapTrap:" << std::endl;
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
