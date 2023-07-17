/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:28 by plau              #+#    #+#             */
/*   Updated: 2023/07/17 10:52:20 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
	public:
		/* Orthodox canonical form */
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		
		/* Requred by PDF */
		void		convert(std::string input);

		/* Member function */
		bool		isChar(std::string input);
		bool		isDouble(std::string input);
		bool		isFloat(std::string input);
		bool		isInt(std::string input);
		int			charToInt(std::string input);
		float		charToFloat(std::string input);
		double		charToDouble(std::string input);
		void		floatToChar(std::string input);
		int			floatToInt(std::string input);
		void		floatToFloatandDouble(std::string input);
		
		
	private :
		
};

#endif
