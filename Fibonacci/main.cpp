#include "fibonacci.h"

#include <boost/multiprecision/cpp_int.hpp>

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>


using cpp_int = boost::multiprecision::cpp_int;

void print_fibonacci(int number);
void print_fibonacci(int from, int count);

template<typename T>
auto make_fibonacci_list(std::size_t num)
{
	std::vector<T> v(num, 1);
	std::adjacent_difference(std::begin(v), std::prev(std::end(v)), std::next(std::begin(v)), std::plus<>());
	return v;
}

template<typename ForwardIt>
void print_list(ForwardIt first, ForwardIt last)
{
	std::copy(first, last,
		std::ostream_iterator<typename std::iterator_traits<ForwardIt>::value_type>(std::cout, ", "));
}

template<typename Container>
void print_list(const Container& cont)
{
	print_list(std::begin(cont), std::end(cont));
}


int main()
{
	std::system("chcp 1251");

	const auto fibonacci_numbers = make_fibonacci_list<int>(20);
	print_list(fibonacci_numbers);
	return 0;
}


void print_fibonacci(int number)
{
	std::cout << "Число Фибоначчи от " << number << ": " << fibonacci<cpp_int>(number) << std::endl;
}

void print_fibonacci(int from, int count)
{
	std::copy_n(fibonacci_coroutine<cpp_int>(from).begin(), count, 
		std::ostream_iterator<cpp_int>(std::cout, ", "));
}
