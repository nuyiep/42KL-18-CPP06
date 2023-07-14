/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:32 by plau              #+#    #+#             */
/*   Updated: 2023/07/14 18:57:08 by plau             ###   ########.fr       */
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

bool	ScalarConverter::isChar(std::string input)
{
	if (input.size() == 1 && !isdigit(input[0]))
		return (true);
	else
		return (false);
}

bool	ScalarConverter::isDouble(std::string input)
{
	try
	{
		std::stod(input);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

bool	ScalarConverter::isFloat(std::string input)
{
	if (std::stof(input) && input[input.length() - 1] == 'f')
		return (true);
	else
		return (false);
}

bool	ScalarConverter::isInt(std::string input)
{
	int		i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
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
		std::cout << "char: " << input << std::endl;
		std::cout << "int: " << charToInt(input) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << charToFloat(input) << "f"<< std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << charToDouble(input) << std::endl;
		exit(5);
	}
	if (isFloat(input) == true)
	{
		std::cout << "is a float" << std::endl;
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
	throw std::runtime_error("cannot be converted");
}
