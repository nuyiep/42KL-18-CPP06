/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:53:28 by plau              #+#    #+#             */
/*   Updated: 2023/07/12 21:09:57 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	class Base
	{
		public:
			virtual void foo() {}
	};
	class Derived : public Base {};

	Base* basePtr = new Derived();
	Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); //downcasting

	if (derivedPtr != 0)
	{
		//cast was successful
		std::cout << "Cast successful." << std::endl;
		derivedPtr->foo();
	}
	else
	{
		std::cout << "Cast failed." << std::endl;
	}
}
