#include "pch.h"
#include "fibonacci.h"

#include <cstdint>


TEST(NegativeNumbers, Test) {

    for (auto number : { -4, -1, -5, -122, -10000, -123 })
        EXPECT_EQ(fibonacci<int>(number), 0);

}

TEST(NonnegativeNumbers, SmallNumbers) {

    constexpr int numbers[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
        377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711 };

    constexpr auto countNumbers = std::size(numbers);
    for (std::size_t n = 0; n < countNumbers; ++n)
        EXPECT_EQ(fibonacci<int>(n), numbers[n]);

}

TEST(LargeNumbers, Num30) {
    EXPECT_EQ(fibonacci<int>(30), 832040);
}

TEST(LargeNumbers, Num34) {
    EXPECT_EQ(fibonacci<int>(34), 5702887);
}

TEST(LargeNumbers, Num38) {
    EXPECT_EQ(fibonacci<int>(38), 39088169);
}

TEST(LargeNumbers, Num42) {
    EXPECT_EQ(fibonacci<int>(42), 267914296);
}

TEST(LargeNumbers, Num46) {
    EXPECT_EQ(fibonacci<int>(46), 1836311903);
}

TEST(LargeNumbers, Num47) {
    EXPECT_EQ(fibonacci<std::uint64_t>(47), static_cast<std::uint64_t>(2971215073));
}
