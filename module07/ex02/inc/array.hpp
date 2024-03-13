/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:16 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/13 10:05:41 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class Type>
class Array {

	public:
		Array( void );
		Array ( unsigned int n );
		Array( Array const & other );
		~Array( void );

		Array& Array=( Array const & other );
		Array& Array=[]( Array const & other );

		size_t	size( void );

	private:
		Type* _arr[];
	
};

#endif // !ARRAY_HPP
