/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:41:52 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/15 19:55:39 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap {
    
    private:
    
        bool    gate_keeper_mode;

    public:

        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& src);
		ScavTrap&	operator=(const ScavTrap& src);
		~ScavTrap(void);

        void    guardGate(void);
        void	attack(const std::string& target);

		bool	getMode();
};

#endif
