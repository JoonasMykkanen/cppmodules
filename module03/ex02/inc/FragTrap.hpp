/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:34:33 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 11:38:31 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "../inc/ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap {
	public:
	
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & other );
		FragTrap& operator=( FragTrap const & other );
		~FragTrap( void );

		void	highFivesGuys( void );

	private:
	
};

#endif // !FRAGTRAP_H
