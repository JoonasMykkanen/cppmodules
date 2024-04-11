/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:33:34 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/11 10:03:41 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <limits>
# include <deque>

# define LIMIT_PRINTING 1
# define EMPTY -1

typedef std::chrono::high_resolution_clock chrono;
typedef std::pair<int, int>		intpair;
typedef std::vector<intpair>	pairvect;
typedef std::deque<intpair>		pairdeque;


template <typename Type, typename Pair>
class PmergeMe {
	public:
		PmergeMe( int size, char** numbers );
		~PmergeMe();

		void	printOriginal();
		void	printSorted();
		bool	checkSorted();
		void	timeDiff();
		void	sort();

	private:
		PmergeMe();
		PmergeMe( PmergeMe<Type, Pair> const & other );
		PmergeMe<Type, Pair> &operator=( PmergeMe<Type, Pair> const & other );
		
		void	_createPairs ( char** numbers );
		size_t	_binarySearch( int needle );
		void	_insertSort( size_t n );
		size_t	_jacobsthal( size_t n );
		void	_startUpSorted();
		void	_megeSmall();
		void	_sortPairs();

		Pair	_pairs;		// Pairs
		Type	_sorted;	// S array
		char**	_arg;		// X values
		size_t	_amount;	// X size

		chrono::time_point 	_startTime;
		chrono::time_point	_endTime;

};

# include "../src/PmergeMe.tpp"

#endif