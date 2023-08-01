/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:34:33 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/31 10:55:29 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "../inc/ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap {
	public:
	
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & other );
		FragTrap& operator=( FragTrap const & other );
		~FragTrap( void );

		void	highFivesGuys( void );
	
};

#endif // !FRAGTRAP_H
