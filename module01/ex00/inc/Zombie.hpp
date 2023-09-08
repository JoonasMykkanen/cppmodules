/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:23:30 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/08 11:41:49 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
	public:
	
		Zombie( std::string name );
		~Zombie( void );

		void	announce( void );

	private:

		std::string	_name;
		
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif