/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:42:32 by jmykkane          #+#    #+#             */
/*   Updated: 2023/08/31 07:42:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

static int	checkInput(std::string file, std::string s1, std::string s2) {
	if (file.empty() || s1.empty() || s2.empty()) {
		std::cout << "Error with input" << std::endl;
		return (FAIL);
	}
	return (OK);	
}

static void	sedIsForLosers(char **args) {
	std::string filename = args[1];
	std::string	s1 = args[2];
	std::string	s2 = args[3];

	if (checkInput(filename, s1, s2) == FAIL)
		return ;

	std::ifstream	infile;
	infile.open(filename);
	if (!infile) {
        std::cerr << "Unable to open file test.txt";
        return ;
    }
	
	std::ofstream	outfile;
	outfile.open(filename.append(".replace"));
	if (!outfile) {
        std::cerr << "Unable to open file test.txt";
        return ;
    }

	std::string output;
	std::string	line;
    while (std::getline(infile, line)) {
		output.append(line);
    }
	infile.close();

	size_t pos = 0;
	while ((pos = output.find(s1, pos)) != std::string::npos) {
    	output.erase(pos, s1.length());
    	output.insert(pos, s2);
    	pos += s2.length();
	}
	
	outfile << output;
	outfile.close();
}

int	main(int argc, char **argv) {

	if (argc == 4) {
		sedIsForLosers(argv);
	} else {
		std::cout << "Error with input" << std::endl;
	}

	return (0);
}