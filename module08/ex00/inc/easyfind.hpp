/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:27:45 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/14 14:00:06 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

template <typename Type>
typename Type::iterator	easyfind(Type haystack, int needle) {
	typename Type::iterator it = std::find(haystack.begin(), haystack.end(), needle);

	if (it == haystack.end())
		throw std::out_of_range("Easyfind: Needle not found in haystack");
	
	return it;
}

#endif // !EASYFIND_HPP
