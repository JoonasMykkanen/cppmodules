/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 17:28:01 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA {
	public:

		HumanA( Weapon weapon );
		~HumanA( void );

		void	attack( void );

	private:

		std::string	name;
		Weapon*		weapon;
};

#endif // !HUMANA_H