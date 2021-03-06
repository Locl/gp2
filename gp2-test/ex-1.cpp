#include <boost/test/unit_test.hpp>

#include <iostream>
#include "../gp2/prime.h"
#include<stdio.h>
#include<conio.h>

void test_nth_prime(int expected, unsigned int a, unsigned int d, unsigned int n) {
	const char* result = (expected == nth_prime(a, d, n)) ? "ok" : "invalid";
	std::cout << "nth_prime(" << a << ", " << d << ", " << n << ") ... " << result << std::endl;
}

BOOST_AUTO_TEST_SUITE(ex1)
BOOST_AUTO_TEST_CASE(test_nth_prime) {
	BOOST_CHECK_EQUAL(2,nth_prime(1, 1, 1));
	BOOST_CHECK_EQUAL(103,nth_prime(103,230, 1));
	BOOST_CHECK_EQUAL(5107,nth_prime(307,24,79));
	//while(!kbhit());
// ...
}
BOOST_AUTO_TEST_SUITE_END()

/*
int main() {
	test_nth_prime(     2,    1,   1,   1);
	test_nth_prime(   103,  103, 230,   1);
	test_nth_prime(  5107,  307,  24,  79);
	test_nth_prime(  6709,  179,  10, 203);
	test_nth_prime( 12037,  271,  37,  39);
	test_nth_prime( 14503,  253,  50,  85);
	test_nth_prime( 22699,  259, 170,  40);
	test_nth_prime( 25673,  269,  58, 102);
	test_nth_prime( 92809,  367, 186, 151);
	test_nth_prime( 93523,   27, 104, 185);
	test_nth_prime(412717,  331, 221, 177);
	test_nth_prime(899429, 9075, 337, 210);
	
	return 0;
}
*/