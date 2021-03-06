#include <boost/test/unit_test.hpp>

#include <iostream>
#include "../gp2/prime.h"
#include<stdio.h>
#include<conio.h>

void test_nth_not_prime(int expected, unsigned int a, unsigned int d, unsigned int n) {
	const char* result = (expected == nth_prime(a, d, n)) ? "ok" : "invalid";
	std::cout << "nth_prime(" << a << ", " << d << ", " << n << ") ... " << result << std::endl;
}

BOOST_AUTO_TEST_SUITE(ex2)
BOOST_AUTO_TEST_CASE(test_nth_not_prime) {
	BOOST_CHECK_EQUAL(30,nth_not_prime(9, 21, 2));
	BOOST_CHECK_EQUAL(-2,nth_not_prime(103,230, 1));
	BOOST_CHECK_EQUAL(144,nth_not_prime(12,33,5));
	//while(!kbhit());
// ...
}
BOOST_AUTO_TEST_CASE(test_gcd) {
	BOOST_CHECK_EQUAL(1,gcd(2, 3));
	BOOST_CHECK_EQUAL(10,gcd(20, 30));
	BOOST_CHECK_EQUAL(1,gcd(103, 230));
	//while(!kbhit());
// ...
}
BOOST_AUTO_TEST_SUITE_END()