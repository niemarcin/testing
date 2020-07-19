#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <algorithm>
#include <vector>

// TEST_CASE("Sorting 1, 2, 3 should give 1, 2, 3", "[sort]") {
//     std::vector<int> v{1, 2, 3};
//     std::vector<int> expected{1, 2, 3};
//     std::sort(v.begin(), v.end());

//     // REQUIRE(v[0] == 1);
//     // REQUIRE(v[1] == 2);
//     // REQUIRE(v[2] == 3);
//     ////OR
//     REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
// }

// TEST_CASE("Sorting 3, 2, 1 should give 1, 2, 3", "[sort]") {
//     std::vector<int> v{3, 2, 1};
//     std::vector<int> expected{1, 2, 3};
//     std::sort(v.begin(), v.end());

//     REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
// }
////OR

TEST_CASE("Sorting permutation of 1, 2, 3 should give 1, 2, 3", "[sort]") {
    const std::vector<int> expected{1, 2, 3};

    SECTION("Sorting 1, 2, 3") {
        std::vector<int> v{1, 2, 3};
        std::sort(v.begin(), v.end());
     
        REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
    }

    SECTION("Sorting 3, 2, 1") {
        std::vector<int> v{3, 2, 1};
        std::sort(v.begin(), v.end());
     
        REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
    }
}

SCENARIO("Vector should be sorted", "[sort]") {
    GIVEN("Vector v and expected = {1, 2, 3}") {
        const std::vector<int> expected{1, 2, 3};
        auto v = GENERATE(  std::vector<int>{3,2,1},
                            std::vector<int>{3,1,2},
                            std::vector<int>{1,2,3},
                            std::vector<int>{2,1,3});

        WHEN("Vector v is sorted ascending") {
            std::sort(v.begin(), v.end());

            THEN("Vector v { " << v[0] <<v[1] << v[2] << "} should be equal to expected") {
                REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
            }
        }
    }
    

    GIVEN("Vector v = {3,2,1,4} and expected = {4,3,2,1}") {
        std::vector<int> v{3,2,1,4};
        const std::vector<int> expected{4,3,2,1};

        WHEN("Vector v is sorted ascending") {
            std::sort(v.rbegin(), v.rend());

            THEN("Vector v should be equal to expected") {
                REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
            }
        }
    }


    GIVEN("An empty vector v and expected") {
        using Pair = std::pair<std::vector<int>, std::vector<int>>;

        auto [v, expected] = GENERATE(Pair{{}, {}}),
                                      Pair{{1}, {1}});

        WHEN("vector v is sorted") {
            std::sort(v.begin(), v.end());

            THEN("v is not changed") {
                REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
            }
        }
    }

    GIVEN("vectors v and expected with one element") {
        std::vector<int> v{1};
        std::vector<int> expected{1};

        WHEN("vector v is sorted") {
            std::sort(v.begin(), v.end());

            THEN("v is equal to expected") {
                REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
            }
        }
    }

    GIVEN("A string text") {
        std::string text{"text"};
        std::string expected{"ettx"};

        WHEN("string text is sorted") {
            std::sort(text.begin(), text.end());

            THEN("string text should be equal to expected") {
                REQUIRE_THAT(text, Catch::Matchers::Equals(expected));
            }
        }
    }

    GIVEN("A string tExT") {
        std::string text{"tExT"};
        std::string expected{"ETtx"};

        WHEN("string text is sorted") {
            std::sort(text.begin(), text.end());

            THEN("string text should be equal to expected") {
                REQUIRE_THAT(text, Catch::Matchers::Equals(expected));
            }
        }
    }

}

SCENARIO("Vector should be sorted with comparator", "[sort]") {
    GIVEN("Vector expected = {3,2,1}") {
        const std::vector<int> expected{3,2,1};

        AND_GIVEN("Vector v = {1,2,3}") {
            std::vector<int> v{1, 2, 3};

            WHEN("Vector v is sorted descending") {
                std::sort(v.begin(), v.end(), std::greater<int>());

                THEN("Vector v should be equal to expected") {
                    REQUIRE_THAT(v, Catch::Matchers::Equals(expected));
                }
            }
        }
    }
}