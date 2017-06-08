#include <matrix.hpp>
#include <catch.hpp>
#include <iostream>

using namespace std;

SCENARIO("matrix init", "[init]") {
	Matrix matrix;
	REQUIRE(matrix.rows() == 0);
	REQUIRE(matrix.columns() == 0);




