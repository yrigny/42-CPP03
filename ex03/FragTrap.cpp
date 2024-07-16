/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:41:01 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 19:53:47 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;	
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap default constructor called for " << name << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called for " << src.getName() << std::endl;  
	*this = src;
}

FragTrap&   FragTrap::operator=(const FragTrap& src) {
	std::cout << "FragTrap copy assignment operator called for " << src.getName() << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called for " << getName() << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		this->setEnergyPoints(-1);
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << getName() << " is too tired to attack!" << std::endl;
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "FragTrap " << getName() << ": High five, guys!" << std::endl;
}
