/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:26:02 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/18 10:19:00 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <cctype>
# include <string>
# include <map>

class Harl {
	
	public:
		Harl( void );
		~Harl( void );

		void    complain( std::string level );

		typedef void	(Harl::*functionPtr)();
		functionPtr 	getFunctionPtr( std::string level );
	
	private:
		std::map<std::string, functionPtr>	_funcMap;

		void	_info( void );
		void	_debug( void );
		void	_error( void );
		void	_warning( void );

};

#endif // !HARL_H
