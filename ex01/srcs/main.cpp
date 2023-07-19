/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:43:38 by plau              #+#    #+#             */
/*   Updated: 2023/07/18 12:14:28 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"serializer.hpp"

/* Same address because serializing and deserializing the same pointer */
int main()
{
	Data		A;
	Serializer 	S;
	uintptr_t 	U;
	Data*		B;

	/* Storing and printing struct */
	std::cout << BOLD_GREEN << "*****Data Struct*****" << RESET << std::endl; 
	A.intraID = "plau";
	A.batchYear = 2022;
	A.fun = true;
	A.grade = 'A';
	std::cout << "Intra ID: " << A.intraID << std::endl;
	std::cout << "Batch Year: " << A.batchYear << std::endl;
	/* set the stream to display boolean values as true or false (not 1 or 0) */
	std::cout << std::boolalpha;
	std::cout << "Fun: " << A.fun << std::endl;
	std::cout << "Grade: " << A.grade << std::endl;
	std::cout << "Data struct address: " << &A << std::endl;

	/* Convert pointer to uintptr_t */
	std::cout  << BOLD_GREEN << "*****[SERIALIZE] Convert pointer to uintptr_t******" << RESET << std::endl;
	U = S.serialize(&A);
	std::cout << "Raw Address of Data: " << U << std::endl;
	
	/* Convert uintptr_t to a pointer to Data */
	std::cout << BOLD_GREEN << "*****[DESERIALIZE] Convert uintptr_t to pointer to Data" << RESET << std::endl;
	B = S.deserialize(U);
	std::cout << "Address of pointer to Data: " << B << std::endl;
	std::cout << "Intra ID: " << B->intraID << std::endl;
	std::cout << "Batch Year: " << B->batchYear << std::endl;
	std::cout << "Fun: " << B->fun << std::endl;
	std::cout << "Grade: " << B->grade << std::endl;
}
