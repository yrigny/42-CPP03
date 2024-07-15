/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:08:05 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/13 11:38:33 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap    a("a");
    ClapTrap    b("b");
    // set attack damage for a and b
    a.setAttackDamage(3);
    b.setAttackDamage(5);
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
	a.beRepaired(4);
	b.beRepaired(4);
	a.getStat();
	b.getStat();
    // set new attack damage for a and b
    a.setAttackDamage(6);
	b.setAttackDamage(10);
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
	a.beRepaired(5);
	b.beRepaired(5);
	a.getStat();
	b.getStat();
	return 0;
}