/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:38 by asarikha          #+#    #+#             */
/*   Updated: 2024/04/05 07:53:24 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& other ) {
	*this = other;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ){
	(void) other;
	return *this;
}

void PmergeMe::printArg( int argc, char **argv, std::string type ) {
	int len = argc;
	if (len > PRINT_PRECISION)
		len = PRINT_PRECISION;
	
	std::cout << "<" << type << ">Before: ";
	for (int i = 1; i < len; i++) {
		std::cout << argv[i] << " ";
	}
	
	if (argc > PRINT_PRECISION )
		std::cout << "[...]" << std::endl;
	else
		std::cout << std::endl;
}

void PmergeMe::mergeVector(int start , int mid, int end) {
    int n1 = mid - start + 1; 
	int n2 = end - mid; 

	// two arrays for sorting
	std::vector<int> Left(n1);
	std::vector<int> Right(n2);

	// copy from start to mid into left
	for (int i = 0; i < n1; i++) {
		Left[i] = _veccerson[start + i];
	}

    // copy from mid to end into right
	for (int i = 0; i < n2; i++) {
		Right[i] = _veccerson[mid + 1 + i];
	}

	int RIGHT_INDEX = 0;
	int LEFT_INDEX = 0;
	// sorting+merging the split arrays into vec, starts each round at 0
	for (int i = start; i <= end; i++) {
		if (RIGHT_INDEX == n2) {
			_veccerson[i] = Left[LEFT_INDEX];
			LEFT_INDEX++;
		}
		else if (LEFT_INDEX == n1) {
			_veccerson[i] = Right[RIGHT_INDEX];
			RIGHT_INDEX++;
		}
		else if (Right[RIGHT_INDEX] > Left[LEFT_INDEX]) {
			_veccerson[i] = Left[LEFT_INDEX];
			LEFT_INDEX++;
		}
		else {
			_veccerson[i] = Right[RIGHT_INDEX];
			RIGHT_INDEX++;
		}
	}
}

void PmergeMe::insertionSortVec(int start, int end ) {
    for (int i = start; i < end; i++) {
        unsigned int tempVal = _veccerson[i + 1];
        int j = i + 1;
        while (j > start && _veccerson[j - 1] > tempVal) // if curr pos is bigger than next pos
		{
            _veccerson[j] = _veccerson[j - 1];
            j--; // count down till 0
        }
        _veccerson[j] = tempVal;
	}
}

void PmergeMe::mergeInsertVec(int start, int end ) {
	if (end - start > 2) {
		int mid = (start + end) / 2;
		mergeInsertVec(start, mid);
		mergeInsertVec(mid + 1, end); 
		mergeVector(start, mid, end);
	}
	else {
		insertionSortVec(start, end);
	}
}

void PmergeMe::sortVector(int argc, char **argv){
	printArg(argc, argv, "vector");
	std::clock_t start = std::clock();

	_veccerson.reserve(argc);
	for (int i = 1; i < argc; i++) {
		_veccerson.push_back(std::stoul(argv[i]));
	}
	mergeInsertVec(0, _veccerson.size() - 1);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	printVector();
	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::vector<>: " 
		 << time_taken << " microsecond" << std::endl;
}


void PmergeMe::printList( void ) {
	std::list<unsigned int>::const_iterator it;
	size_t	counter = 0;
	
	std::cout << "<list>After:  ";
	for (it = _listerson.begin(); it != _listerson.end() && counter < PRINT_PRECISION; it++, counter++) {
		std::cout << *it << " ";
	}

	if (_listerson.size() > PRINT_PRECISION)
		std::cout << "[...]" << std::endl;
	else
		std::cout << std::endl;
}

void PmergeMe::printVector( ) {
	std::vector<unsigned int>::const_iterator it;
	size_t	counter = 0;
	
	std::cout << "<vector>After:  ";
	for (it = _veccerson.begin(); it != _veccerson.end() && counter < PRINT_PRECISION; it++, counter++) {
		std::cout << *it << " ";
	}

	if (_veccerson.size() > PRINT_PRECISION)
		std::cout << "[...]" << std::endl;
	else
		std::cout << std::endl;
}

static std::list<unsigned int>::iterator advance(std::list<unsigned int>::iterator it, int n) {
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            ++it;
        }
    }
	else if (n < 0) {
        for (int i = 0; i > n; --i) {
            --it;
        }
    }
	return it;
}

void PmergeMe::mergeList(int start , int mid, int end) {
	int n1 = mid - start + 1; 
	int n2 = end - mid;

	// two arrays for sorting
	std::list<int> Left;
	std::list<int> Right;

	// fill the halfes with the numbers (0 till half and half till end)
	for (int i = 0; i < n1; i++) { 
		Left.push_back(*advance(_listerson.begin(), start + i)); // std:next : gives next iterator, at pos n after the start pos
	}

	for (int i = 0; i < n2; i++) {
		Right.push_back(*advance(_listerson.begin(), mid + 1 + i));
	}

	int RIGHT_INDEX = 0;
	int LEFT_INDEX = 0;
	// sorting+merging the split arrays into int_vec, starts each round at 0
	for (int i = start; i <= end; i++) {
		if (RIGHT_INDEX == n2) {
			*advance(_listerson.begin(), i) = Left.front(); // front returns reference to first element in the list
			Left.pop_front();
			LEFT_INDEX++;
		}
		else if (LEFT_INDEX == n1) {
			*advance(_listerson.begin(), i) = Right.front();
			Right.pop_front();
			RIGHT_INDEX++;
		}
		else if (Right.front() > Left.front()) {
			*advance(_listerson.begin(), i) = Left.front(); // insert front element from left array into list at post after i;
			Left.pop_front(); // then take it out
			LEFT_INDEX++;
		}
		else {
			*advance(_listerson.begin(), i) = Right.front();
			Right.pop_front();
			RIGHT_INDEX++;
		}
	}
}

void PmergeMe::insertionSortList(int start, int end ) {
	for (int i = start; i < end; i++) {
        unsigned int tempVal = *advance(_listerson.begin(), i + 1);
        int j = i + 1;
		// if curr pos is bigger than next pos
        while (j > start && *advance(_listerson.begin(), j - 1) > tempVal) 
		{
            *advance(_listerson.begin(), j) = *advance(_listerson.begin(), j - 1);
            j--; // count down till 0
        }
		//insert element at correct position
        *advance(_listerson.begin(), j) = tempVal; 
	}
}

void PmergeMe::mergeInsertList(int start, int end ) {
	// divide into paired groups until num of groups wanted reached
	if (end - start > 2) {
		int mid = ( start + end ) / 2;
		mergeInsertList(start, mid);
		mergeInsertList(mid + 1, end); 
		mergeList(start, mid, end);
	}
	else {
		insertionSortList(start, end);
	}
}

void PmergeMe::sortList(int argc, char **argv) {
	printArg(argc, argv, "list");
	std::clock_t start = std::clock();

	for (int i = 1; i < argc; i++)
		_listerson.push_back(std::stoul(argv[i]));
	mergeInsertList(0, _listerson.size() - 1);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	printList();
	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::list<> : " 
		 << time_taken << " microsecond" << std::endl;
	
}