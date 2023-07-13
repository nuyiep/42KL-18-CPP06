/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:28 by plau              #+#    #+#             */
/*   Updated: 2023/07/13 20:55:51 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <string>
#include <iostream>

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
		bool		isInt(std::string input);
		
	private :
		
};

#endif
