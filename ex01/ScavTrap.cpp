/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:26:32 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/13 21:41:20 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->gateKeeperMode = false;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;	
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap default constructor called for " << name << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called for " << src.getName() << std::endl;  
	*this = src;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "ScavTrap copy assignment operator called for " << src.getName() << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		this->setEnergyPoints(-1);
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " is too tired to attack!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (gateKeeperMode == false) {
		gateKeeperMode = true;
		std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
	}
	else {
		gateKeeperMode = false;
		std::cout << "ScavTrap " << getName() << " is no more in Gate keeper mode!" << std::endl;	
	}
}