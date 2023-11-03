#include "catch2/catch_all.hpp"
#include "fact.h"

TEST_CASE("fact test") {
	int facts[] = {1, 1, 2, 6, 24, 120, 720};
	for (int i = 0; i < sizeof(facts)/sizeof(int); ++i) {
		REQUIRE(factorial(i) == facts[i]);
	}
}