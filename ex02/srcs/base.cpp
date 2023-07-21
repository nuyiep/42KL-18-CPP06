/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:57:53 by plau              #+#    #+#             */
/*   Updated: 2023/07/20 20:59:48 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

Base::~Base()
{
}

void Base::forDebug()
{
	std::cout << BOLD_MAGENTA << "I am Base" << RESET << std::endl;
}
