/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:37:31 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/13 10:06:51 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename Type>
void	iter(Type* arr, size_t len, void (*fn)(Type)) {
	for (size_t i = 0; i < len; i++) {
		fn(arr[i]);
	}
}

#endif // !ITER_HPP

