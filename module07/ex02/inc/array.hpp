/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:16 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/04 12:46:15 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class Type>
class Array {

	public:
		Array( void ) { _arr = new[]; };
		Array ( unsigned int n ) { _arr = new[n]; };
		~Array( void ) { delete[] _arr; };

	private:
		Type* _arr[];
};

#endif // !ARRAY_HPP
