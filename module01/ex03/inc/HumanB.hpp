/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:22 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/16 10:12:15 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB {
	public:

		HumanB( std::string newName );
		~HumanB( void );
		
		void	attack( void );
		void	setWeapon( Weapon &newWeapon );

	private:

		std::string	_name;
		Weapon		*_weapon;
	
};

#endif // !HUMANB_H