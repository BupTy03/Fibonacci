#include "fibonacci.h"

#include <boost/multiprecision/cpp_int.hpp>

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
#include <cassert>


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
	using value_type = typename std::iterator_traits<ForwardIt>::value_type;
	std::copy(first, last, std::ostream_iterator<value_type>(std::cout, ", "));
}

template<typename Container>
void print_list(const Container& cont)
{
	print_list(std::begin(cont), std::end(cont));
}


int main()
{
	std::system("chcp 1251");

	print_fibonacci(20);

	const auto fibonacci_numbers = make_fibonacci_list<int>(20);
	print_list(fibonacci_numbers);
	return 0;
}


void print_fibonacci(int number)
{
	assert(number >= 0);
	std::cout << "Fibonacci for " << number << ": " << fibonacci<cpp_int>(number) << std::endl;
}

void print_fibonacci(int from, int count)
{
	assert(from >= 0);
	assert(count >= 0);

	if (count == 0) return;

	std::copy_n(fibonacci_coroutine<cpp_int>(from).begin(), count, 
		std::ostream_iterator<cpp_int>(std::cout, ", "));
}
