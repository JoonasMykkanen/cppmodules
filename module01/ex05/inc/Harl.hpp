/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:26:02 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 14:43:04 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# define MAP_LEN 4

# include <iostream>
# include <cctype>
# include <string>

class Harl {
	
	public:
		Harl( void );
		~Harl( void );

		void    complain( std::string level );
		void	StringToLower(std::string& str);

		typedef void	(Harl::*functionPtr)();
		functionPtr 	getFunctionPtr( std::string level );
	
	private:
		// Correct way to do it would be to use one std::map :)
		std::string	_nameMap[4];
		functionPtr	_ptrMap[4];

		void	_info( void );
		void	_debug( void );
		void	_error( void );
		void	_warning( void );

};

#endif // !HARL_H
