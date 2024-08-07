/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:27:00 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 19:56:02 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class   ClapTrap {

	protected:

		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		ClapTrap&	operator=(const ClapTrap& src);
		~ClapTrap(void);

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		const std::string&	getName(void) const;
		void				setHitPoints(int amount);
		unsigned int		getHitPoints(void) const;
		void				setEnergyPoints(int amount);
		unsigned int		getEnergyPoints(void) const;
		void				setAttackDamage(unsigned int amount);
		unsigned int		getAttackDamage(void) const;
};

#endif