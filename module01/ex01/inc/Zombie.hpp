/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:30:34 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/12 14:01:18 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
	public:

		Zombie( void );
		~Zombie ( void );

		void	announce( void );
		void	setName( std::string name );

	private:

		std::string name;
};

Zombie* zombieHorde( int n, std::string name );

#endif // !ZOMBIE_H
