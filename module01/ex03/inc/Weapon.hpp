/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:14 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/08/29 09:22:37 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class	Weapon {
	public:

		Weapon( std::string type );
		~Weapon( void );

		void		setType( std::string type );
		std::string const & getType( void );

	private:
		std::string _type;
};

#endif // !WEAPON_H