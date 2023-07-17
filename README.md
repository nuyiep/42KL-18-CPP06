# 42KL-18-CPP06

This module is designed to help you understand the different casts in CPP.

**Static cast**

	- implicit type conversion
	- static memory allocation is done before the program is executed
	- complier does allocation and deallocation
	- E.g. 
		int num = 10;
		double d = static_cast<double>(num); //numeric conversion

		Base* basePtr = new Derived();
		Derived* derivedPtr = static_cast<Derived*>(basePtr); //pointer conversion

**Reinterpret cast**

	- low-level type conversions between unrelated types
	- E.g. converting a pointer to an integer type or vice versa
	- often not recommended to use it unless you have a very specific need
		and fully understand the potential risks
	- E.g. 
		int num = 10;
		char* charPtr = reinterpret_cast<char*>(&num); //pointer to integer conversion
		int* intPtr = reinterpret_cast<int*>(charPtr); // pointer type conversion

**Dynamic cast**

	- safe type conversions in polymorphic class hierarchies
	  with runtime type checking
	- dynamic memory allocation is done during run-time
	- programmer does allocation and deallocation
	- if the cast is not valid, dynamic_cast returns a null pointer (for pointer 
		types) or throws a std::bad_cast_exception (for ref types)
	- dynamic_cast requires the use of polymorphic classes (classes with at least
		one virtual function) to enable runtime type identification
	- E.g. 
		class Base
		{
			virtual void foo() {}
		};
		class Derived : public Base {};

		Base* basePtr = new Derived();
		Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); //downcasting

		if (derivedPtr != nullptr)
		{
			//cast was successful
			derivedPtr->foo();
		}
  	- An example of the dynamic cast
   <img width="602" alt="Screenshot 2023-07-12 at 21 23 32" src="https://github.com/nuyiep/42KL-18-CPP06/assets/53002130/078a07c1-bd55-42b9-a521-15585ca68386">

**Special floating point literals**
	- -inff negative infinity (negative floating point infinity)
		values that are smaller (more negative) than the min representable value
		in the floating point format
		E.g. in single-precision (32-bit) floating point representation,
			-inff represents the smallest negative value that can be represented
	- +inff positive infinity
	- nanf not a number- undefined or indeterminate operation
		(e.g. square root of a negative number)

**Non-printable character in ASCII**
	- 0 to 31 and 127 are non-printable characters
