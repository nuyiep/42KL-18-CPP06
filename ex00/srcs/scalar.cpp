/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:32 by plau              #+#    #+#             */
/*   Updated: 2023/07/13 20:55:53 by plau             ###   ########.fr       */
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

void	ScalarConverter::convert(std::string input)
{
	if (isChar(input) == true)
	{
		std::cout << "char: " << input << std::endl;
		
	}
	else
		std::cout << "cannot be converted" << std::endl;
}
