#include "fibonacci.h"
#include <iostream>


void print_fibonacci(int number);

int main()
{
	std::system("chcp 1251");

	//print_fibonacci(0);
	//print_fibonacci(1);
	//print_fibonacci(2);
	//print_fibonacci(3);
	//print_fibonacci(4);
	print_fibonacci(5);
	//print_fibonacci(6);
	//print_fibonacci(6);

	return 0;
}


void print_fibonacci(int number)
{
	std::cout << number << "-ое число Фибоначчи: " << fibonacci(number) << std::endl;
}
