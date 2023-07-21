/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:57:37 by plau              #+#    #+#             */
/*   Updated: 2023/07/20 20:59:41 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* Randomly instanciates A, B or C and returns the instance as a Base pointer */
/* rand() - 0 to 32,767 */
/* No need dynamic casting because A is derived from Base */
/* It is an upcasting- can convert a pointer to a derived class type */
/* 					   to a pointer to its base class type */
/* Can use the instance pointer to call member function */
Base* generate(void)
{
	srand(time(0)); //seed the random number generator with the current time 
	//or srand(time(nullptr))
	
	int	randomNum = (rand() % 3 + 1); // + 1 so that num range from 1-3 not 0-2
	if (randomNum == 1)
	{
		Base* instance = new A; // A* instance = new A;
		return (instance);
	}
	if (randomNum == 2)
		return (new B);
	if (randomNum == 3)
		return (new C);
	return (NULL);
}

/* Pointer if casting unsuccessful, will return NULL */
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer C" << std::endl;
}

/* Reference if casting unsuccessful, the exception std::bad_cast is thrown */
/* https://en.cppreference.com/w/cpp/language/dynamic_cast */
/* [shouldnt be used here] */
/*		aPtr pointing towards derived class A - if cast fails, aPtr will be a null pointer */
/* 		A* aPtr = dynamic_cast<A*>(&p); */
void	identify(Base& p)
{
	try
	{
		/* ref to the derived class */
		/* any changes made to it will directly affect the original obj referred to by p */
		// A &a = dynamic_cast<A&>(p);
		//(void)a;
		/* creates a new obj */
		/* any changes made to a will not affect the obj referred to by p */
		A a = dynamic_cast<A&>(p);
		std::cout << "A ref" << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << "[Not A] ";
		// std::cerr << e.what() << '\n';
	}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B ref" << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << "[Not B] ";
		// std::cerr << e.what() << '\n';
	}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C ref" << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << "[Not C] ";
		// std::cerr << e.what() << '\n';
	}
}

int main()
{
	std::cout << BOLD_GREEN << "Testing for upcasting- no need dynamic cast" << RESET<< std::endl;
	Base* instance;
	instance = generate();
	if (!instance)
		std::cout << "upcasting failed" << std::endl;
	instance->forDebug();
	std::cout << BOLD_GREEN << "Testing for dynamic casting (pointer)" << RESET<< std::endl;
	identify(instance);
	std::cout << BOLD_GREEN << "Testing for dynamic casting (ref)" << RESET<< std::endl;
	identify(*instance);
	delete instance;
	return (0);
}
