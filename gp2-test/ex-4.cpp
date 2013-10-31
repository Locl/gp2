#include <boost/test/unit_test.hpp>
#include "../gp2/mcxiSum.h"

BOOST_AUTO_TEST_SUITE(Example4Test)

BOOST_AUTO_TEST_CASE(TestValidCase1) {
    try {
		gp2::McxiSum sum(10);

		BOOST_TEST_PASSPOINT();
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_SUITE_END()
