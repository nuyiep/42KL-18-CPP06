/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:52:32 by plau              #+#    #+#             */
/*   Updated: 2023/07/17 19:53:14 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include "serializer.hpp"

struct Data
{
	std::string intraID;
	int			batchYear;
	bool		fun;
	char		grade;
};

#endif
