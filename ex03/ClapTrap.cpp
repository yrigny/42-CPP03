/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:07:21 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 19:16:12 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	return;	
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap default constructor called for " << name << std::endl;
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
    std::cout << "ClapTrap copy constructor called for " << src.getName() << std::endl; 
    *this = src;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& src) {
    std::cout << "ClapTrap copy assignment operator called for " << src.getName()  << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called for " << getName() << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		this->setEnergyPoints(-1);
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << getName() << " is too tired to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > getHitPoints())
		setHitPoints(-getHitPoints());
	else
		setHitPoints(-amount);
	std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		setEnergyPoints(-1);
		setHitPoints(amount);
		std::cout << "ClapTrap " << getName() << " repairs itself with " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << getName() << " is too tired to repair itself!" << std::endl;
}

const std::string&	ClapTrap::getName(void) const {
	return name;
}

void    ClapTrap::setHitPoints(int amount) {
    if (amount < 0 && hit_points + amount < 0)
		hit_points = 0;
	else
		hit_points += amount;
}

unsigned int    ClapTrap::getHitPoints(void) const {
    return this->hit_points;
}

void    ClapTrap::setEnergyPoints(int amount) {
	if (amount < 0 && energy_points + amount < 0)
		energy_points = 0;
	else
		energy_points += amount;
}

unsigned int    ClapTrap::getEnergyPoints(void) const {
    return this->energy_points;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->attack_damage = amount;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->attack_damage;
}
