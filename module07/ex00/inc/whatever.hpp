/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:31 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/15 12:30:53 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Type>
void	swap(Type& first, Type& second) {
	Type temp = first;
	
	first = second;
	second = temp;
}

template <typename Type>
const Type&	min(Type const & first, Type const & second) {
	return first < second ? first : second;
}

template <typename Type>
Type	max(Type const& first, Type const& second) {
	return first > second ? first : second;
}
