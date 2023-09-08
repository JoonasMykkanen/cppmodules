/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:27:28 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/09/08 14:28:02 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "DEBUG complaint:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "INFO complaint:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "WARNING complaint:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "ERROR complaint:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Testing an invalid level:" << std::endl;
    harl.complain("Invalid Level");

    return 0;
}