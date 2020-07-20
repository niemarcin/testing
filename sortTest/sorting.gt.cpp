#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using Comparator = std::function<bool(const int &a, const int &b)>;
using VectorsPair = std::tuple<std::vector<int>, std::vector<int>, Comparator>;

struct SortVectorTestFixture : public ::testing::TestWithParam<VectorsPair>
{};

TEST_P(SortVectorTestFixture, GivenAnInputVectorWhenVectorIsSortedThenItIsEqualToExpected) {
    // GIVEN
    auto [input, expected, comparator] = GetParam();

    // WHEN
    std::sort(input.begin(), input.end(), comparator);

    // THEN
    ASSERT_EQ(input, expected);
}

INSTANTIATE_TEST_SUITE_P(SomeVectors,
                         SortVectorTestFixture,
                         ::testing::Values(VectorsPair{{3, 2, 1}, {1, 2, 3}, [](int lhs, int rhs){ return lhs < rhs; }},
                                           VectorsPair{{1, 2, 3}, {1, 2, 3}, std::less<int>{}},
                                           VectorsPair{{2, 1, 3}, {1, 2, 3}, std::less<int>{}},
                                           VectorsPair{{3, 1, 2}, {1, 2, 3}, std::less<int>{}},
                                           VectorsPair{{}, {}, std::less<int>{}},
                                           VectorsPair{{1}, {1}, std::less<int>{}},
                                           VectorsPair{{3, 2, 1}, {3, 2, 1}, std::greater<int>{}},
                                           VectorsPair{{1, 2, 3}, {3, 2, 1}, std::greater<int>{}},
                                           VectorsPair{{2, 1, 3}, {3, 2, 1}, std::greater<int>{}},
                                           VectorsPair{{3, 1, 2}, {3, 2, 1}, std::greater<int>{}},
                                           VectorsPair{{}, {}, std::greater<int>{}},
                                           VectorsPair{{1}, {1}, std::greater<int>{}}
                         ));


using StringPair = std::pair<std::string, std::string>;

struct SortStringTestFixture : public ::testing::TestWithParam<StringPair>
{};

TEST_P(SortStringTestFixture, GivenAStringTextWhenTextIsSortedThenItIsEqualToEttx) {
    // GIVEN
    auto [input, expected] = GetParam();

    // WHEN
    std::sort(input.begin(), input.end());

    // THEN
    ASSERT_EQ(input, expected);
    ASSERT_THROW(input.end(), std::runtime_error);
}

INSTANTIATE_TEST_SUITE_P(SomeStrings,
                         SortStringTestFixture,
                         ::testing::Values(StringPair{{"text"}, {"ettx"}},
                                           StringPair{{"tExTtextTEXT"}, {"EETTTXetttxx"}}

                         ));

TEST(SortTestV4Fixture, GivenAVector3214WhenVectorIsSortedWithReverseIteratorsThenItIsEqualTo4321) {
    // GIVEN
    std::vector<int> v {3, 2, 1, 4};
    std::vector<int> expected {4, 3, 2, 1};

    // WHEN
    std::sort(v.rbegin(), v.rend());

    // THEN
    ASSERT_EQ(v, expected);
}

// struct SortTestFixture : public ::testing::Test {
//     template <typename T>
//     void sortDescendingAndCheck(T & input, const T & expected) {
//         // WHEN
//         std::sort(input.begin(), input.end(), std::greater<int>{});

//         // THEN
//         ASSERT_EQ(input, expected);
//     }
// };

// TEST_F(SortTestFixture, GivenAStringTextWhenTextIsSortedDescendingThenItIsEqualToXtte) {
//     // GIVEN
//     std::string text{"text"};
//     std::string expected{"xtte"};

//     sortDescendingAndCheck(text, expected);
// }

// TEST_F(SortTestFixture, GivenAStringtExTtextTEXTWhenTextIsSortedDescendingThenItIsEqualToxxttteXTTTEE) {
//     // GIVEN
//     std::string text{"tExTtextTEXT"};
//     std::string expected{"xxttteXTTTEE"};

//     sortDescendingAndCheck(text, expected);
// }