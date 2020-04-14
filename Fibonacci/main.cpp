#include "fibonacci.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <memory>


using cpp_int = boost::multiprecision::cpp_int;

void print_fibonacci(int number);

int main()
{
	std::system("chcp 1251");

	print_fibonacci(1000000);
	return 0;
}


void print_fibonacci(int number)
{
	std::cout << "Число Фибоначчи от " << number << ": " << fibonacci<cpp_int>(number) << std::endl;
}
