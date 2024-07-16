/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:04:31 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 19:48:15 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap default constructor called for " << name << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "DiamondTrap copy constructor called for " << src.getName() << std::endl;
	*this = src;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src) {
	std::cout << "DiamondTrap copy assignment operator called for " << src.getName() << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << getName() << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}
