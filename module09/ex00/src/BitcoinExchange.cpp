/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:45:12 by jmykkane          #+#    #+#             */
/*   Updated: 2024/04/05 08:01:17 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::_file = "data.csv";

BitcoinExchange::BitcoinExchange() {
	this->loadDatabase();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other ) {
	*this = other;
}

BitcoinExchange&  BitcoinExchange::operator=( BitcoinExchange const & other ){
	if (this != &other){
		this->_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool	validateDateFormat( std::string const & key ) {
	std::regex	pattern("^\\d{4}-\\d{2}-\\d{2}$");
	return std::regex_match(key, pattern);
}

static bool validatePrice( std::string const & value ) {
	try {
        size_t pos;
        float price = std::stof(value, &pos);
        if (price < 0 || pos != value.size())
            return false;
    } catch(std::exception& error) {
		return false;		
	}
    return true;
}

void BitcoinExchange::loadDatabase() {
	std::ifstream	infile(_file);
	std::string		line;

	if (infile.fail()) {
		throw std::runtime_error("Could not open [data.csv], make sure it's in the root of the repo");
	}

	std::getline(infile, line);
	while (std::getline(infile, line)) {
		std::stringstream	entry(line);
		std::string			value;
		std::string 		key;
		
		if (std::getline(entry, key, ',') && (entry >> value)) {
			if (!validateDateFormat(key))
				throw std::runtime_error("Date was incorrectly formatted [yyyy-mm-dd]");
			if (!validatePrice(value))
				throw std::out_of_range("Malformatted price");
			_data[key] = value;
		} else {
			throw std::runtime_error("database seems to be corrupted (invalid line found), invalid data found, sucks to be you! :)");
		}
	}
}

float BitcoinExchange::getRateForDate(const std::string& date)
{
    if (_data.count(date) > 0) {
		return std::stof(_data[date]);
	}
	
	auto it = _data.lower_bound(date);
	if (it == _data.begin())
		return -1;
	if (it == _data.end() || it->first != date)
		--it;
	
	return std::stof(it->second);
}

void BitcoinExchange::loadInputFile( std::string const & inputFile ) {
	std::ifstream	infile(inputFile);
	std::string		line;

	if (infile.fail()) {
		throw std::runtime_error("Could not open argument file, make sure it's in the root of the repo.");
	}

	std::getline(infile, line);
	while (std::getline(infile, line)) {
		size_t delimiter = line.find('|');

		if (delimiter == std::string::npos || line.length() < delimiter + 2) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delimiter - 1);
		if (!validateDateFormat(date)) {
			std::cerr << "Error: invalid date" << std::endl;
			continue;
		}
		
		std::string balance = line.substr(delimiter + 2);
		if (!validatePrice(balance)) {
			std::cerr << "Error: invalid balance" << std::endl;
			continue;
		}

		float amount = std::stof(balance);
		if (amount > 1000) {
			std::cerr << "Error: too large number" << std::endl;
			continue;
		}

		float price = getRateForDate(date);
		if (price < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		
		std::cout << date << " => ";
		std::cout << std::fixed << std::setprecision(2) << amount;
		std::cout << " = " << std::fixed << std::setprecision(2);
		std::cout << amount * price << std::endl;
	}
}