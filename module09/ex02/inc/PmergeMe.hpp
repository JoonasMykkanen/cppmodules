/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:40 by asarikha          #+#    #+#             */
/*   Updated: 2024/04/02 10:39:07 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

# define MICROSECOND 100000

class PmergeMe
{		
	public:
		PmergeMe( void );
		PmergeMe( const PmergeMe& other );
		PmergeMe &operator=( const PmergeMe& other );
		~PmergeMe(void);

		void sortVector( int argc, char **argv );
		void sortList( int argc, char **argv );

		void printArg( int argc, char **argv, std::string type );
		void printVector( void );
		void printList( void );
	
		private:
			std::vector<unsigned int> 	_veccerson;
			std::list<unsigned int>		_listerson;
			
};




#endif