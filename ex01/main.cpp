/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:24:53 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/13 21:45:06 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
	ScavTrap	a("a");
	ScavTrap	b("b");
	// set attack damage for a and b
	a.getStat();
	b.getStat();
	// a attacks b
	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	a.getStat();
	b.getStat();
	// b attacks a
	b.attack("a");
	a.takeDamage(b.getAttackDamage());
	a.getStat();
	b.getStat();
	// a and b repair themselves
	a.beRepaired(10);
	b.beRepaired(10);
	a.getStat();
	b.getStat();
	// a attacks b
	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	a.getStat();
	b.getStat();
	// b attacks a
	b.attack("a");
	a.takeDamage(b.getAttackDamage());
	a.getStat();
	b.getStat();
	// a and b repair themselves
	a.beRepaired(10);
	b.beRepaired(10);
	a.getStat();
	b.getStat();
	return 0;
}