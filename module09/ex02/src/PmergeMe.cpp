/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:38 by asarikha          #+#    #+#             */
/*   Updated: 2024/04/02 10:54:48 by jmykkane         ###   ########.fr       */
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

static void mergeVector(std::vector<unsigned int>& vec, int start , int mid, int end)
{
    int n1 = mid - start + 1; 
	int n2 = end - mid; 

	// two arrays for sorting
	std::vector<int> Left(n1);
	std::vector<int> Right(n2);

	// copy from start to mid into left
	for (int i = 0; i < n1; i++) {
		Left[i] = vec[start + i];
	}

    // copy from mid to end into right
	for (int i = 0; i < n2; i++) {
		Right[i] = vec[mid + 1 + i];
	}

	int RIDX = 0;
	int LIDX = 0;

	// sorting+merging the split arrays into vec, starts each round at 0
	for (int i = start; i <= end; i++) 
	{
		if (RIDX == n2)
		{
			vec[i] = Left[LIDX];
			LIDX++;
		}
		else if (LIDX == n1)
		{
			vec[i] = Right[RIDX];
			RIDX++;
		}
		else if (Right[RIDX] > Left[LIDX])
		{
			vec[i] = Left[LIDX];
			LIDX++;
		}
		else
		{
			vec[i] = Right[RIDX];
			RIDX++;
		}
	}
}

static void insertionSortVec(std::vector<unsigned int>& vec, int start, int end ) {
    
    for (int i = start; i < end; i++)
	{
        unsigned int tempVal = vec[i + 1];
        int j = i + 1;
        while (j > start && vec[j - 1] > tempVal) // if curr pos is bigger than next pos
		{
            vec[j] = vec[j - 1];
            j--; // count down till 0
        }
        vec[j] = tempVal;
	}
}

static void mergeInsertVec(std::vector<unsigned int>& vec, int start, int end ) {
		
	if (end - start > 2)
	{
		int mid = (start + end) / 2;
		mergeInsertVec(vec, start, mid);
		mergeInsertVec(vec, mid + 1, end); 
		mergeVector(vec, start, mid, end); // merge sort
	}
	else
	{
		insertionSortVec(vec, start, end);
	}
}

void PmergeMe::sortVector(int argc, char **argv){
	printArg(argc, argv, "vector");
	std::clock_t start = std::clock();

	for (int i = 1; i < argc; i++) {
		_veccerson.push_back(std::stoul(argv[i]));
	}
	mergeInsertVec(_veccerson, 0, _veccerson.size() - 1);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	printVector();
	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << time_taken << " microsecond" << std::endl;
}



void PmergeMe::printArg( int argc, char **argv, std::string type ) {
	int len = argc;
	if (len > 10)
		len = 10;
	
	std::cout << "<" << type << ">Before:	";
	for (int i = 1; i < len; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << "[...]" << std::endl;
}


void PmergeMe::printList( void ) {
	std::list<unsigned int>::const_iterator it;
	
	std::cout << "<list>After:	 ";
	for (it = _listerson.begin(); it != _listerson.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "[...]" << std::endl;
}

void PmergeMe::printVector( ) {
	std::vector<unsigned int>::const_iterator it;
	
	std::cout << "<vector>After: ";
	for (it = _veccerson.begin(); it != _veccerson.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "[...]" << std::endl;
}

static std::list<unsigned int>::iterator advance(std::list<unsigned int>::iterator it, int n) {
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            ++it;
        }
    } else if (n < 0) {
        for (int i = 0; i > n; --i) {
            --it;
        }
    }
	return it;
}

static void mergeList(std::list<unsigned int>& list, int start , int mid, int end){

	int n1 = mid - start + 1; 
	int n2 = end - mid;

	// two arrays for sorting
	std::list<int> Left;
	std::list<int> Right;

	// fill the halfes with the numbers (0 till half and half till end)
	for (int i = 0; i < n1; i++) { 
		Left.push_back(*advance(list.begin(), start + i)); // std:next : gives next iterator, at pos n after the start pos
	}

	for (int i = 0; i < n2; i++) {
		Right.push_back(*advance(list.begin(), mid + 1 + i));
	}

	int RIDX = 0;
	int LIDX = 0;
	// sorting+merging the split arrays into int_vec, starts each round at 0
	for (int i = start; i <= end; i++) {
		if (RIDX == n2) {
			*advance(list.begin(), i) = Left.front(); // front returns reference to first element in the list
			Left.pop_front();
			LIDX++;
		}
		else if (LIDX == n1) {
			*advance(list.begin(), i) = Right.front();
			Right.pop_front();
			RIDX++;
		}
		else if (Right.front() > Left.front()) {
			*advance(list.begin(), i) = Left.front(); // insert front element from left array into list at post after i;
			Left.pop_front(); // then take it out
			LIDX++;
		}
		else {
			*advance(list.begin(), i) = Right.front();
			Right.pop_front();
			RIDX++;
		}
	}
}

static void insertionSortList(std::list<unsigned int>& list, int start, int end ) {
	
	for (int i = start; i < end; i++) {
        unsigned int tempVal = *advance(list.begin(), i + 1);
        int j = i + 1;
        while (j > start && *advance(list.begin(), j - 1) > tempVal) // if curr pos is bigger than next pos
		{
            *advance(list.begin(), j) = *advance(list.begin(), j - 1);
            j--; // count down till 0
        }
        *advance(list.begin(), j) = tempVal; //insert element at correct position
	}
}

static void mergeInsertList(std::list<unsigned int>& list, int start, int end ) {
	// divide into paired groups until num of groups wanted reached
	if (end - start > 2) {
		int mid = ( start + end ) / 2;
		mergeInsertList(list, start, mid);
		mergeInsertList(list, mid + 1, end); 
		mergeList(list, start, mid, end);
	}
	else {
		insertionSortList(list, start, end);
	}
}

void PmergeMe::sortList(int argc, char **argv) {
	printArg(argc, argv, "list");
	std::clock_t start = std::clock();

	for (int i = 1; i < argc; i++)
		_listerson.push_back(std::stoul(argv[i]));
	mergeInsertList(_listerson, 0, _listerson.size() - 1);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	printList();
	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << time_taken << " microsecond" << std::endl;
	
}