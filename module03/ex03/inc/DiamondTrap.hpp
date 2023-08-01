/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:34:33 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 11:18:05 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "../inc/ScavTrap.hpp"
# include "../inc/FragTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
	
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( FragTrap const & other );
		DiamondTrap& operator=( DiamondTrap const & other );
		~DiamondTrap( void );

		void	DiamondTrap::whoAmI( void );
		void	DiamondTrap::attack(const std::string& target);

	private:

		std::string	name_;
	
};

#endif // !DIAMONDTRAP_H
