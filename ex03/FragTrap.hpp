/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:41:20 by yrigny            #+#    #+#             */
/*   Updated: 2024/07/16 16:56:04 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class   FragTrap : virtual public ClapTrap {

    public:

        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
		FragTrap&	operator=(const FragTrap& src);
		~FragTrap(void);

        void    highFiveGuys(void);
        void	attack(const std::string& target);
};

#endif
