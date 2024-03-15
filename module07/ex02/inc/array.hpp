/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:16 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/15 12:54:25 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <stdexcept>

template <class Type>
class Array {

	public:

		Array( void ) : _size(0) {
			_memory = nullptr;
		};
		
		Array ( unsigned int n ) : _size(n) {
			_memory = new Type[n]();
		};

		Array( Array const & other ) : _size(other._size) {
            _memory = new Type[other._size]();
            for (unsigned int i = 0; i < other._size; i++)
                _memory[i] = other._memory[i];
		};

		~Array( void ) {
			if (_memory != nullptr)
				delete[] _memory;
		};

		Array& operator=( Array const & other ) {
			if (this != &other) {
				if (_memory)
					delete[] _memory;
				_memory = new Type[other._size]();
				for (size_t i = 0; i < other._size; i++)
					_memory[i] = other._memory[i];
			}
		};

		Type& operator[]( unsigned int index ) {
			if (index >= _size || index < 0)
				throw (std::out_of_range("Index out of bounds"));
			
			return _memory[index];
		};

		const Type& operator[]( unsigned int index ) const {
			if (index >= _size || index < 0)
				throw (std::out_of_range("Index out of bounds"));
			
			return _memory[index];
		};

		size_t	size( void ) const { return _size; }

	private:
		Type*	_memory;
		size_t	_size;
	
};

#endif // !ARRAY_HPP
