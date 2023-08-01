	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2023/07/28 10:49:58 by joonasmykka       #+#    #+#             */
	/*   Updated: 2023/07/28 11:36:47 by joonasmykka      ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#ifndef SCAVTRAP_H
	# define SCAVTRAP_H

	# include "ClapTrap.hpp"
	# include <iostream>
	# include <string>

	class ScavTrap : virtual public ClapTrap {
		public:
		
			ScavTrap( void );
			ScavTrap( std::string name );
			ScavTrap( ScavTrap const & other );
			ScavTrap& operator=( ScavTrap const & other );
			~ScavTrap( void );

			void	attack( const std::string& target );
			void	guardGate( void );
			
	};

	#endif // !SCAVTRAP_H