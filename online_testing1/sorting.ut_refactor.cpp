//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    out << "{ ";
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        out << *it;
        if (it != --vec.end()) {
            out << " ; ";
        }
    }
    out << " }\n";
    return out;
}

SCENARIO("Vector should be sorted", "[sort]") {
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

    GIVEN("An input vector v and expected") {
        using Pair = std::pair<std::vector<int>, std::vector<int>>;
        
        auto p = GENERATE(Pair{{}, {}},
                          Pair{{1}, {1}},
                          Pair{{3, 2, 1}, {1, 2, 3}},
                          Pair{{3, 1, 2}, {1, 2, 3}},
                          Pair{{1, 2, 3}, {1, 2, 3}},
                          Pair{{1, 3, 2}, {1, 2, 3}},
                          Pair{{2, 1, 3}, {1, 2, 3}},
                          Pair{{2, 3, 1}, {1, 2, 3}});

        WHEN("vector v is sorted") {
            std::cout << p.first << "\n";
            std::sort(p.first.begin(), p.first.end());

            THEN("v is not changed") {
                REQUIRE_THAT(p.first, Catch::Matchers::Equals(p.second));
            }
        }
    }

    GIVEN("A string text") {
        auto p = GENERATE(std::pair<std::string, std::string>{"text", "ettx"},
                          std::pair<std::string, std::string>{"tExT", "ETtx"});

        WHEN("string text is sorted") {
            std::sort(p.first.begin(), p.first.end());

            THEN("string text should be equal to expected") {
                REQUIRE_THAT(p.first, Catch::Matchers::Equals(p.second));
            }
        }
    }
}
