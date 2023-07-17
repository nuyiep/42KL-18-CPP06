
#include <iostream>

int main()
{
	char c = '~';
	int	x = 0;

	x = sizeof(c);
	std::cout << "size of x:"<< x << std::endl;
}

/* Note: ~ mean home address - non-convertable */
/* 		 has to be '~' */
