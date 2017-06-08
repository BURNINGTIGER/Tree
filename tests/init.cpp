#include <matrix.hpp>
#include <catch.hpp>
#include <iostream>

using namespace std;

SCENARIO("matrix init", "[init]") {
	Matrix matrix;
	REQUIRE(matrix.rows() == 0);
	REQUIRE(matrix.columns() == 0);
}

SCENARIO("params init", "[init with params]") {
	int init = 5;
	Matrix matrix(init, init);
	REQUIRE(matrix.rows() == 5);
	REQUIRE(matrix.columns() == 5);
}

SCENARIO("copy", "[copy]")
{
	int init = 2;
	Matrix m1(init, init);
	Matrix copy(m1);
	REQUIRE(copy.rows() == 2);
	REQUIRE(copy.columns() == 2);
}

SCENARIO("m+", "[m+]")
{
	Matrix A(2, 2);
	Matrix B(2, 2);
	Matrix C(2, 2);
	std::ifstream ("f1.txt") >> A;
	std::ifstream ("f2.txt") >> B;
	std::ifstream ("f3.txt") >> C;
	REQUIRE((A + B) == C);
}

SCENARIO("m*", "[m*]")
{
	Matrix A (2, 2);
	Matrix B (2, 2);
	Matrix C (2, 2);
	std::ifstream("f1.txt") >> A;
	std::ifstream("f2.txt") >> B;
	std::ifstream("f4.txt") >> C;
	REQUIRE((A*B) == C);
}



