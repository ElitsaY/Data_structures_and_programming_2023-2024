#include "catch2/catch_all.hpp"
#include "dynamic_array.hpp"


TEST_CASE("Test index operator")
{
    DynamicArray<int> arr;
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
    }

    for (int i = 0; i < arr.size(); ++i) {
	    REQUIRE(arr[i] == i);
    }
}