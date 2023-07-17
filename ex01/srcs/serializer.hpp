/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:00:28 by plau              #+#    #+#             */
/*   Updated: 2023/07/17 19:53:30 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "data.hpp"

class Serializer
{
	public:
		/* Orthodox canonical form */
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

		/* Required by PDF */
		// takes a pointer and converts it to the unsigned int type uintptr_t
		uintptr_t serialize(Data *ptr);
		Data* deserialize(uintptr_t raw);
	private:
};

#endif
