/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:24:14 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 17:05:35 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class	Weapon {
	public:

		Weapon( std::string type );
		~Weapon( void );

		void	setType( std::string type );
		std::string const & getType( void );

	private:
		std::string type;
};

#endif // !WEAPON_H