/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:42:32 by jmykkane          #+#    #+#             */
/*   Updated: 2023/07/13 11:49:45 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

static int	checkInput(int count, char **args) {
		
}

static void	sedIsForLosers(int count, char **args) {
	
	if (checkInput(count, args) == FAIL)
		return ;
	
}

int	main(int argc, char **argv) {

	if (argc == 4) {
		sedIsForLosers(argc, argv);
	}

	return (0);
}