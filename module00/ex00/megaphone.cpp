/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:32:32 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/15 20:38:57 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	int	i = 1;
	int j = 0;
	
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		while(argv[i]) {
			while(argv[i][j]) {
				argv[i][j] = toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
			j = 0;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}