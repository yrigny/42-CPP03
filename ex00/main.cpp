/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:08:05 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/15 19:26:32 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
# define GREEN "\033[1;32m"
# define NONE "\033[0m"

void	getStat(ClapTrap& obj) {
	std::cout << GREEN "Status: " NONE << obj.getName() << " has " << obj.getHitPoints() << " hit points, " << obj.getEnergyPoints() << " energy points, " << obj.getAttackDamage() << " attack damage." << std::endl;
}

int main(void) {
	// constructor message
    ClapTrap    a("a");
    ClapTrap    b("b");

	std::cout << std::endl << "setting a and b's attack damage to 5..." << std::endl;
	a.setAttackDamage(5);
	b.setAttackDamage(5);
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
	a.beRepaired(1);
	b.beRepaired(1);
	getStat(a);
	getStat(b);

	std::cout << std::endl << "case: takeDamage() when damage received > HP" << std::endl;
	std::cout << "setting b's attack damage to 10..." << std::endl;
	b.setAttackDamage(10);
	b.attack("a");
    a.takeDamage(b.getAttackDamage());
	getStat(a);
	getStat(b);

	std::cout << std::endl << "case: beRepaired() when hit points = 0" << std::endl;
	a.beRepaired(1);
	getStat(a);

	std::cout << std::endl << "case: beRepaired() when energy points = 0" << std::endl;
	std::cout << "setting b's energy points to 0..." << std::endl;
	b.setEnergyPoints(-b.getEnergyPoints());
	b.beRepaired(1);
	getStat(b);

	// destructor message
	std::cout << std::endl;

	return 0;
}
