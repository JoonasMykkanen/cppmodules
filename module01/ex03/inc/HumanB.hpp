/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:22 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 17:26:00 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB {
	public:

		HumanB( void );
		~HumanB( void );
		
		void	attack( void );

	private:

		std::string	name;
		Weapon*		weapon;
	
};

#endif // !HUMANB_H