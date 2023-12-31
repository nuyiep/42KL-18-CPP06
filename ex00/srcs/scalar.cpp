/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:32 by plau              #+#    #+#             */
/*   Updated: 2023/07/20 20:18:59 by plau             ###   ########.fr       */
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

/* Convert from string to int */
/* then convert int to char */
/* stoi conversion fails will throw exception */
void ScalarConverter::floatOrDoubleOrIntToChar(std::string input)
 {
	int			y;
	std::string x;
	
	if (input == "-inff" || input == "+inff" || input == "nanf" ||
		input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "char: Impossible" << std::endl;
		return ;
	}
	y = 0;
	try
	{
		y = std::stoi(input);
		if ((0 <= y && y <= 31) || y == 127)
		{
			std::cout << "char: Non displayable" << std::endl;
			return ;
		}
		if (y >= 32 && y <= 126)
		{
			x = static_cast<char>(y);
			std::cout << "char: '" << x << "'"<< std::endl;
			return ;
		}
		std::cout << "char: Non displayable"<< std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Float-char] Cannot be converted" << '\n';
		exit(10);
	}
 }

 void	ScalarConverter::floatOrDoubleToInt(std::string input)
 {
	int		x;

	x = 0;
	try
	{
		if (input == "-inff" || input == "+inff" || input == "nanf" ||
			input == "-inf" || input == "+inf" || input == "nan")
		{
			std::cout << "int: Impossible" << std::endl;
			return ;
		}
		x = std::stoi(input);
		std::cout << "int: " << x << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot be converted" << '\n';
		exit(88);
	}
 }

/* Convert to double first */ 
/* input.find('.') searches for the first occurence of .  */
/* std::string::npos - constant static member of std::string class */
/* 					 - represents the max value for a size_t (unsigned int) */
/* 					 - used to indicate that a value of pos is not found */
void	ScalarConverter::floatOrDoubleToFloatandDouble(std::string input)
{
	double	x;
	int		precision;
	int		dotPos;
	int		length;

	x = 0;
	try
	{
		x = std::stod(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	precision = 0;
	dotPos = 0;
	length = 0;
	if (input.find('.') == std::string::npos) // . not found  
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << x << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << x << std::endl;
		return ;
	}
	if (input.find('.') != std::string::npos) // . is found
	{
		dotPos = input.find('.');
		length = input.length();
		precision = length - 1 - dotPos - 1;
		if (precision == 0)
		{
			std::cout << "float: " << std::fixed << std::setprecision(1) << x << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << x << std::endl;
			return ;
		}
		std::cout << "float: " << std::fixed << std::setprecision(precision) << x << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision) << x << std::endl;
	}
}

/* std::fixed - ensures that the float value is printed with */
/* 				fixed-point notation */
void	ScalarConverter::convert(std::string input)
{
	if (input.compare("nan") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(4);
	}
	if (isChar(input) == true)
	{
		std::cout << "is a char" << std::endl;
		std::cout << "char: '" << input << "'"<< std::endl;
		std::cout << "int: " << charToInt(input) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << charToFloat(input) << "f"<< std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << charToDouble(input) << std::endl;
		exit(5);
	}
	if (isFloat(input) == true)
	{
		std::cout << "is a float" << std::endl;
		floatOrDoubleOrIntToChar(input);
		floatOrDoubleToInt(input);
		floatOrDoubleToFloatandDouble(input);
		exit (7);	
	}
	if (isDouble(input) == true)
	{
		std::cout << "is a double" << std::endl;
		floatOrDoubleOrIntToChar(input);
		floatOrDoubleToInt(input);
		floatOrDoubleToFloatandDouble(input);
		exit(6);
	}
	if (isInt(input) == true)
	{
		std::cout << "is int" << std::endl;
		floatOrDoubleOrIntToChar(input);
		std::cout << "int: " << input << std::endl;
		floatOrDoubleToFloatandDouble(input);
		exit(8);
	}
	throw std::runtime_error("Throw: Cannot be converted");
}

bool isConvertable(std::string& input) {
	int dotCount = 0;
	
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	for (unsigned int i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i])) {
			if (i == 0 && (input[i] == '+' || input[i] == '-'))
				continue;
			else if (i == input.length() - 1 && input[i] == 'f')
				continue;
			else if (input[i] == '.' && dotCount == 0)
				dotCount++;
			else
				return false;
		}
	}
	return true;
}

/* std::fixed - ensures that the float value is printed with */
/* 				fixed-point notation */
void	ScalarConverter::convert_xuerui(std::string input)
{
	double d;
	int precision = 1;
	
	if (input.compare("nan") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(4);
	}
	if (isConvertable(input)) {
		if (input.length() == 1 && !isdigit(input[0]))
			d = input[0];
		else {
			try {
				d = std::stod(input);
			} catch (...) {
				throw std::runtime_error("Throw: Cannot be converted");
			}
		}
		if (input.find('.') != std::string::npos) {
			precision = input.length() - input.find('.') - 1;
			if (input[input.length() - 1] == 'f') {
				precision--;
			}
		}
		if (precision < 1)
			precision = 1;
		if (d <= 32 || d >= 127)
			std::cout << "char: " << "Unprintable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(d) << 'f' << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(d) << std::endl;
	}
	else {
		throw std::runtime_error("Throw: Cannot be converted");
	}
	return;
}


