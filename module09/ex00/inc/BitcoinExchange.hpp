/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:45:25 by jmykkane          #+#    #+#             */
/*   Updated: 2024/03/29 13:24:29 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
# define BTC_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <sstream>
# include <limits>
# include <string>
# include <regex>
# include <ctime>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & other );
		BitcoinExchange& operator=( BitcoinExchange const & other);
		~BitcoinExchange();

		void	loadDatabase();
		void	loadInputFile( std::string const & inputFile );	

	private:
		float	getRateForDate( std::string const & date );
		
		std::map<std::string, std::string>	_data;
		static const std::string			_file;
		
};

#endif // !BTC_HPP
