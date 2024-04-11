/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:38:07 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/11 10:09:05 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ------------------------------ ORTHODOX CANONICAL FORM ------------------------------ //
template <typename Type, typename Pair>
PmergeMe<Type, Pair>::PmergeMe(int size, char **numbers) : _amount(size) {
	_arg = numbers;
}

template <typename Type, typename Pair>
PmergeMe<Type, Pair>::PmergeMe( PmergeMe<Type, Pair> const & other ) {
	*this = other;
}

template <typename Type, typename Pair>
PmergeMe<Type, Pair>	&PmergeMe<Type, Pair>::operator=( PmergeMe<Type, Pair> const & other ) {
	_sorted = other._sorted;
	_pairs = other._pairs;
	_amount = other._amount;
	return *this;
}

template <typename Type, typename Pair>
PmergeMe<Type, Pair>::~PmergeMe() {
	
}


// ------------------------------ STATIC ------------------------------ //
template <typename Type>
typename Type::iterator createIterator(size_t index, Type &container) {
	typename Type::iterator it = container.begin();
	std::advance(it, index);
	return (it);
}



// ------------------------------ SORTING ------------------------------ //
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::sort() {
	_startTime = chrono::now();

	_createPairs(_arg);				// 1.
	_sortPairs();					// 2.
	_insertSort(_pairs.size()); 	// 3.
	_startUpSorted();				// 4.
	_megeSmall();					// 5.
	
	_endTime = chrono::now();
}

// PART 1 -->
// Group the elements of X into [n/2] pairs of elements arbitraily,
// leaving one element unpaired if there is an odd number of elements.
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::_createPairs(char** numbers) {
	size_t i = 0;

	for (; i + 1 < static_cast<size_t>(_amount - (_amount % 2)); i++) {
		if (i % 2)
			continue;
		intpair tmp;
		tmp.first = std::atoi(numbers[i]);
		tmp.second = std::atoi(numbers[i + 1]);
		_pairs.push_back(tmp);
	}
	
	if (_amount % 2) {
		intpair tmp;
		
		if (numbers[i + 1])
			tmp.first = std::atoi(numbers[i + 1]);
		else 
			tmp.first = std::atoi(numbers[i]);
		
		tmp.second = EMPTY;
		_pairs.push_back(tmp);
	}
}

// PART 2 -->
// Perform [n/2] comparisons, one per pair,
// to determine the larger of the two elements in each pair.
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::_sortPairs() {
	for (size_t i = 0; i != _pairs.size(); i++) {
		if (_pairs.at(i).first < _pairs.at(i).second) // Comparison happens here
			std::swap(_pairs.at(i).first, _pairs.at(i).second);
	}
}

// PART 3 A -->
// Recursively sort the [n/2] larger elements from each pair
// creating a sorted sequence S of [n/2] of the input elemets
// in ascending order.
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::_insertSort(size_t n) {
    if (n <= 1)
        return ;
	
    _insertSort(n - 1);
	
    typename Pair::iterator last = createIterator(n - 1, _pairs);
    typename Pair::iterator	it = _pairs.begin();
    while (it != last) {
        if ((*it).first >= (*last).first) {
            _pairs.insert(it, *last);
            last = createIterator(n, _pairs);
            _pairs.erase(last);
            break ;
        }
        it++;
    }
}

// PART 4 -->
// Insert at the start of S
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::_startUpSorted() {
	for (size_t i = 0; i != _pairs.size(); i++)
		_sorted.push_back(_pairs.at(i).first);
	if (_pairs.at(0).second != EMPTY)
		_sorted.insert(_sorted.begin(), _pairs.at(0).second);
	_pairs.at(0).second = EMPTY;
}

// PART 5 -->
// Insert the remaining [n/2] - 1 elements of X / S into S, one at a time.
// Use Binary search in subsequences of S to determine position at which element should be inserted
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::_megeSmall() {
    size_t	jacob = 0;
    size_t	jacob_index = 1;
    size_t	prev_jacob = 0;
    size_t	which = 0;

    while (_sorted.size() < _amount) {
        prev_jacob = jacob;
        jacob = _jacobsthal(jacob_index);

        if (jacob > _pairs.size())
            jacob = _pairs.size() - 1;
		
        which = jacob;
        jacob_index++;
		
        while (which > prev_jacob) {
			if (which >= _pairs.size() || _pairs.at(which).second == EMPTY) {
				which--;
				continue;
			}
			
			size_t index = _binarySearch(_pairs.at(which).second);
			if (index >= _sorted.size())
				return ;
			
            typename Type::iterator where = createIterator(index, _sorted);
            _sorted.insert(where, _pairs.at(which).second);
            _pairs.at(which).second = EMPTY;

            which--;
        }
    }
}




// ------------------------------ ALGO HELPERS ------------------------------ //
template <typename Type, typename Pair>
size_t	PmergeMe<Type, Pair>::_jacobsthal(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return _jacobsthal(n - 1) + 2 * _jacobsthal(n - 2);
}

template <typename Type, typename Pair>
size_t	PmergeMe<Type, Pair>::_binarySearch( int needle ) {
	size_t right = _sorted.size();
	size_t left = 0;
	size_t mid = 0;

	while (left < right && mid < _sorted.size()) {
		mid = left + (right - left) / 2;
		
		if (_sorted.at(mid) < needle)
			left = mid + 1;
		else
			right = mid;
	}
	
	return left;
}



// ------------------------------ HELPERS ------------------------------ //
template <typename Type, typename Pair>
bool	PmergeMe<Type, Pair>::checkSorted() {
	for (size_t i = 0; i + 1 < _sorted.size(); i++)
		if (_sorted.at(i) > _sorted.at(i + 1))
			return (false);
	for (size_t i = 0; i != _pairs.size(); i++)
		if (_pairs.at(i).second != EMPTY)
			return (false);
	return (true);
}





// ------------------------------ PRINTING ------------------------------ //
template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::printOriginal() {
	std::cout << "Before: ";
	for (size_t i = 0; _arg[i]; i++)
	{
		if (LIMIT_PRINTING && i > 10) {
			std::cout << " [...]" << std::endl;
			break;
		}
		
		std::cout << _arg[i];
		if (_arg[i + 1])
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::printSorted() {
	if (!checkSorted())
		std::cout << "Sorting failed..." << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i != _sorted.size(); i++)
	{
		if (LIMIT_PRINTING && i > 10) {
			std::cout << " [...]" << std::endl;
			break;
		}

		std::cout << _sorted.at(i);
		if (i + 1 != _sorted.size())
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

template <typename Type, typename Pair>
void	PmergeMe<Type, Pair>::timeDiff() {
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(_endTime - _startTime).count();
	if (duration < 1000)
		std::cout << duration << " us" << std::endl;
	else
		std::cout << duration / 1000 << " ms" << std::endl;
}