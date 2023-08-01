/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:49:58 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 11:27:43 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap {
	public:
	
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & other );
		ScavTrap& operator=( ScavTrap const & other );
		~ScavTrap( void );

		void	attack( const std::string& target );
		void 	guardGate( void );

	private:

		
	
};

#endif // !SCAVTRAP_H