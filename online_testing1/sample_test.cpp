#include "catch.hpp"

#include <algorithm>
#include <vector>

TEST_CASE("Vector of inc sorted integers is sorted inc", "[vector]") {
    std::vector<int> vec{1, 2, 3};
    std::vector<int> expected{1, 2, 3};

    std::sort(vec.begin(), vec.end());
    REQUIRE(vec == expected);
}

TEST_CASE("Vector of dec sorted integers is sorted inc", "[vector]") {
    std::vector<int> vec{3, 2, 1};
    std::vector<int> expected{1, 2, 3};

    std::sort(vec.begin(), vec.end());
    REQUIRE(vec == expected);
}

TEST_CASE("Vector of inc sorted integers is sorted dec", "[vector]") {
    std::vector<int> vec{1,2,3};
    std::vector<int> expected{3,2,1};

    std::sort(vec.begin(), vec.end(),std::greater<int>());
    REQUIRE(vec == expected);
}

TEST_CASE("One vector contains all the elements as second vector", "[vector]") {
    std::vector<int> vec{2,3,1,4,5};
    std::vector<int> expected{2,4,5,1,3};

    REQUIRE_THAT(vec, Catch::Matchers::UnorderedEquals(expected));
}