/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:32 by plau              #+#    #+#             */
/*   Updated: 2023/07/16 00:34:59 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(*this) = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}



/* first scenario: char c to int */
/* convert to ascii value */
int		ScalarConverter::charToInt(std::string input)
{
	int x;

	x = 0;
	x = static_cast<int>(input[0]);
	return (x);
}

/* char: c */
/* float: 99.0f */
float	ScalarConverter::charToFloat(std::string input)
{
	float	x;

	x = 0;
	x = static_cast<float>(input[0]);
	return (x);
}

double	ScalarConverter::charToDouble(std::string input)
{
	double	x;

	x = 0;
	x = static_cast<double>(input[0]);
	return (x);
}

/* Convert to int then to char */
 std::string ScalarConverter::floatToChar(std::string input)
 {
	int			y;
	std::string x;
	
	y = 0;
	y = std::stoi(input);
	x = static_cast<char>(y);
	return (x);
 }

 int	ScalarConverter::floatToInt(std::string input)
 {
	int		x;

	x = 0;
	x = std::stoi(input);
	return (x);
 }

/* Convert to double first */ 
float	ScalarConverter::strToFloat(std::string input)
{
	float	x;

	x = 0;
	if (input.back() == 'f')
	{
		input.pop_back(); // remove the f char
		if (input.find('.') == std::string::npos) // if not found will return std::string::npos
		{
			x = std::stof(input) + 0.0;
			std::cout << "here: " << x << std::endl;
			return (x);
		}
	}
	// x = std::stof(input);
	return (x);
}

/* std::fixed - ensures that the float value is printed with */
/* 				fixed-point notation */
void	ScalarConverter::convert(std::string input)
{
	// if (input[0] == '0')
	// {
	// 	std::cout << "char: Non displayable" << std::endl;
	// 	std::cout << "int: " << input[0] << std::endl;
	// 	std::cout << "float: " << input[0] << ".0f" << std::endl;
	// 	std::cout << "double: " << input[0] << ".0" << std::endl;
	// 	exit(3);
	// }
	// if (input.compare("nan") == 0)
	// {
	// 	std::cout << "char: impossible" << std::endl;
	// 	std::cout << "int: impossible" << std::endl;
	// 	std::cout << "float: nanf" << std::endl;
	// 	std::cout << "double: nan" << std::endl;
	// 	exit(4);
	// }
	if (isChar(input) == true)
	{
		std::cout << "char: '" << input << "'"<< std::endl;
		std::cout << "int: " << charToInt(input) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << charToFloat(input) << "f"<< std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << charToDouble(input) << std::endl;
		exit(5);
	}
	if (isFloat(input) == true)
	{
		std::cout << "is a float" << std::endl;
		std::cout << "char: '" << floatToChar(input) << "'"<< std::endl;
		std::cout << "int: " << floatToInt(input) << std::endl;
		std::cout << "float: " << std::fixed << strToFloat(input) << "f"<< std::endl;
		// std::cout << "double: " << std::fixed << std::setprecision(1) << charToDouble(input) << std::endl;
		exit (7);	
	}
	if (isDouble(input) == true)
	{
		std::cout << "is a double" << std::endl;
		exit(6);
	}
	if (isInt(input) == true)
	{
		
	}
	std::cout << "are u here" << std::endl;
	throw std::runtime_error("cannot be converted");
}
