/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:26:02 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/13 18:51:29 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

class Harl {
	
	public:
		Harl( void );
		~Harl( void );

		void    complain( std::string level );

		typedef void	(Harl::*functionPtr)();
		functionPtr 	getFunctionPtr( std::string level );
	
	private:
		void	info( void );
		void	debug( void );
		void	error( void );
		void	warning( void );

};

#endif // !HARL_H
