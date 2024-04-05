/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:40 by asarikha          #+#    #+#             */
/*   Updated: 2024/04/05 07:50:28 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

# define MICROSECOND 100000
# define PRINT_PRECISION 5

class PmergeMe
{		
	public:
		PmergeMe( void );
		PmergeMe( const PmergeMe& other );
		PmergeMe &operator=( const PmergeMe& other );
		~PmergeMe(void);

		void printArg( int argc, char **argv, std::string type );
		void sortVector( int argc, char **argv );
		void sortList( int argc, char **argv );

	private:
		std::vector<unsigned int> 	_veccerson;
		std::list<unsigned int>		_listerson;

		// Vector functions
		void mergeVector(int start , int mid, int end);
		void insertionSortVec(int start, int end );
		void mergeInsertVec(int start, int end );
		void printVector( void );

		// List functions
		void mergeList(int start , int mid, int end);
		void insertionSortList(int start, int end );
		void mergeInsertList(int start, int end );
		void printList( void );

};




#endif