/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:46:46 by plau              #+#    #+#             */
/*   Updated: 2023/07/19 19:28:26 by plau             ###   ########.fr       */
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
		if (!isdigit(input[i] || input[i] != '.'))
			return (false);
		i++;
	}
	return (true);
}

/* stof doesnt throw exception */
/* it returns "NaN" - which is covered by the else statement */
/* as false */
bool	ScalarConverter::isFloat(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (std::stof(input) && input[input.length() - 1] == 'f')
		return (true);
	else
		return (false);
}

/* stoi - if the conversion is successful, the function */
/* 		  returns the corresponding integer value */
/* 		- else will throw an exception */
bool	ScalarConverter::isInt(std::string input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	try
	{
		if(std::stoi(input) || input == "0")
			return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[isInt] Cannot be converted" << '\n';
		exit(EXIT_FAILURE);
	}
	return (false);
}
