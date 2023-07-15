/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:46:46 by plau              #+#    #+#             */
/*   Updated: 2023/07/15 22:54:27 by plau             ###   ########.fr       */
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
