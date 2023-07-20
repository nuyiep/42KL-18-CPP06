/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:46:46 by plau              #+#    #+#             */
/*   Updated: 2023/07/20 20:19:47 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

bool	ScalarConverter::isChar(std::string input)
{
	if (input.size() == 1 && !isdigit(input[0]))
		return (true);
	else
		return (false);
}

bool	ScalarConverter::isDouble(std::string input)
{
	int	i;
	int	countDots;

	i = 0;
	countDots = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '.')
			countDots++;
		i++;
	}
	if (countDots != 1)
		return (false);
	i = 0;
	while (input[i] != '\0')
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != '+' && input[i] != '-')
			return (false);
		i++;
	}
	return (true);
}

/* can also use string::find - shorter code */
bool	ScalarConverter::isFloat(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	int	i = 0;
	int count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == 'f')
			count++;
		i++;
	}
	if (count != 1)
		return (false);
	if (input[input.length() - 1] != 'f')
		return (false);
	try
	{
		float convertValue = std::stof(input);
		if (convertValue != 0.0)
			return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (false);
}

/* stoi - if the conversion is successful, the function */
/* 		  returns the corresponding integer value */
/* 		- else will throw an exception */
bool	ScalarConverter::isInt(std::string input)
{
	int	i;

	i = -1;
	while (input[++i] != '\0')
	{
		if (!isdigit(input[i]))
		{
			if (i == 0 && (input[i] == '+' || input[i] == '-'))
				continue;
			return (false);
		}
	}
	try
	{
		std::stoi(input);
		return (true);
	}
	catch(...)
	{
		return (false);
	}
	return (false);
}
