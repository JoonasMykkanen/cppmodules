/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:41:51 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/19 10:54:12 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span( void ) : _maxSize(0), _isSorted(false) {}

Span::Span( unsigned int n ) : _maxSize(n), _isSorted(false) {}

Span::Span( Span const & other ) {
	*this = other;
}

Span& Span::operator=( Span const & other ) {
	if (this != &other) {
		_vec = other._vec;
		_maxSize = other._maxSize;
		_isSorted = other._isSorted;
	}
	return *this;
}

Span::~Span( void ) {}

void	Span::addNumber( int num ) {
	if (_vec.size() >= _maxSize)
		throw std::length_error("size already at max capacity");

	_vec.push_back(num);
}

void	Span::addNumbers( std::vector<int> const & nums ) {
	if (_vec.size() + nums.size() > _maxSize)
		throw std::length_error("size already at max capacity");
	
	_vec.insert(_vec.end(), nums.begin(), nums.end());
}

size_t	Span::shortestSpan( void ) {
	if (_vec.size() < 2)
		throw std::length_error("Span too short to check longest distance between elements");
	
	if (!_isSorted) {
		std::sort(_vec.begin(), _vec.end());
		_isSorted = true;
	}

	long int current = LONG_MAX;
	for (auto it = _vec.begin() + 1; it != _vec.end(); ++it) {
		long int span = static_cast<long int>(*(it)) - static_cast<long int>(*(it - 1));
		if (span < current)
			current = span;
	}
		
	return current;
}

size_t	Span::longestSpan( void ) {
	if (_vec.size() < 2)
		throw std::length_error("Span too short to check longest distance between elements");

	long int min = *std::min_element(_vec.begin(), _vec.end());
	long int max = *std::max_element(_vec.begin(), _vec.end());

	return max - min;
}