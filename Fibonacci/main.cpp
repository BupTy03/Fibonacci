#include "fibonacci.h"
#include <iostream>


void print_fibonacci(int number);

int main()
{
	std::system("chcp 1251");

	print_fibonacci(2);
	return 0;
}


void print_fibonacci(int number)
{
	std::cout << number << "-ое число Фибоначчи: " << fibonacci(number) << std::endl;
}
