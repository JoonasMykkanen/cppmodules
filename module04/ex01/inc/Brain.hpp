/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:16:17 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/20 15:21:06 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

class Brain {
	public:
		Brain( void );
		Brain( Brain const & other );
		Brain& operator=( Brain const & other );
		~Brain( void );

		void		setIdea( int index, std::string idea );
		std::string	getIdea( int index);
		
	private:
		std::string	_ideas[100];
};

#endif // !BRAIN_H