#pragma once

#include <cassert>
#include <array>
#include <experimental/generator>


template<typename T>
struct multiply_matrix_2x2 
{
	constexpr inline std::array<T, 4> operator()(const std::array<T, 4>& lhs, const std::array<T, 4>& rhs) const noexcept
	{
		return {
			lhs[0] * rhs[0] + lhs[1] * rhs[2], lhs[0] * rhs[1] + lhs[1] * rhs[3],
			lhs[2] * rhs[0] + lhs[3] * rhs[2], lhs[2] * rhs[1] + lhs[3] * rhs[3]
		};
	}
};


template<typename N>
constexpr inline std::array<N, 4> identity_element(const multiply_matrix_2x2<N>&) noexcept
{
	return { N{1}, N{0}, 
			 N{0}, N{1} };
}


template<typename T, typename N, typename BinaryOperation>
T power(T x, N n, BinaryOperation op)
{
	assert(n >= 0);
	if (n == 0) return identity_element(op);

	while ((n & 1) == 0)
	{
		n >>= 1;
		x = op(x, x);
	}

	T result = x;
	n >>= 1;
	while (n != 0)
	{
		x = op(x, x);
		if ((n & 1) != 0)
			result = op(result, x);

		n >>= 1;
	}

	return result;
}


template<typename R, typename N>
R fibonacci(N n)
{
	if (n <= 0) return R{ 0 };

	return power(std::array<R, 4>{1, 1, 1, 0}, N{ n - 1 }, multiply_matrix_2x2<R>())[0];
}

template<typename R, typename N>
std::experimental::generator<R> fibonacci_coroutine(N n)
{
	if (n <= 0) co_yield R{ 0 };

	const auto mtx = power(std::array<R, 4>{1, 1, 1, 0}, N{ n - 1 }, multiply_matrix_2x2<R>());
	co_yield mtx[0];

	R prev = mtx[1];
	R next = mtx[0];
	while (true)
	{
		R sum = prev + next;
		prev = next;
		next = sum;

		co_yield next;
	}
}
