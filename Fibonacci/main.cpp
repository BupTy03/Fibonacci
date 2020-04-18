#include "fibonacci.h"

#include <boost/multiprecision/cpp_int.hpp>

#include <iostream>
#include <algorithm>
#include <iterator>


using cpp_int = boost::multiprecision::cpp_int;

void print_fibonacci(int number);

int main()
{
	std::system("chcp 1251");

	std::copy_n(fibonacci_coroutine<cpp_int>(50).begin(), 10, std::ostream_iterator<cpp_int>(std::cout, ", "));
	return 0;
}


void print_fibonacci(int number)
{
	std::cout << "Число Фибоначчи от " << number << ": " << fibonacci<cpp_int>(number) << std::endl;
}
