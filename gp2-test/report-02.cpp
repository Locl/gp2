#include <boost/test/unit_test.hpp>
#include <vector>
#include <sstream>
#include "../gp2/compline.h"

BOOST_AUTO_TEST_SUITE(Report02Test)

BOOST_AUTO_TEST_CASE(TestValidCase1) {
	try {
		gp2::CompLine a;
		std::vector<int> matchlist;
		std::stringstream ss;
		a.addPLine(5);
		a.addPLinePoint(0,0);
		a.addPLinePoint(2,0);
		a.addPLinePoint(2,1);
		a.addPLinePoint(4,1);
		a.addPLinePoint(4,0);
		a.addPLine(5);
		a.addPLinePoint(0,0);
		a.addPLinePoint(0,2);
		a.addPLinePoint(-1,2);
		a.addPLinePoint(-1,4);
		a.addPLinePoint(0,4);
		a.addPLine(5);
		a.addPLinePoint(0,0);
		a.addPLinePoint(0,1);
		a.addPLinePoint(-2,1);
		a.addPLinePoint(-2,2);
		a.addPLinePoint(0,2);
		a.addPLine(5);
		a.addPLinePoint(0,0);
		a.addPLinePoint(0,-1);
		a.addPLinePoint(2,-1);
		a.addPLinePoint(2,0);
		a.addPLinePoint(4,0);
		a.addPLine(5);
		a.addPLinePoint(0,0);
		a.addPLinePoint(2,0);
		a.addPLinePoint(2,-1);
		a.addPLinePoint(4,-1);
		a.addPLinePoint(4,0);
		a.addPLine(5);
		a.addPLinePoint(0,0);
		a.addPLinePoint(2,0);
		a.addPLinePoint(2,1);
		a.addPLinePoint(4,1);
		a.addPLinePoint(4,0);
		matchlist = a.comparePLine();
		for(std::vector<int>::iterator it = matchlist.begin(); it != matchlist.end(); it++){
			ss << *it << "\n";
		}
		BOOST_CHECK_EQUAL("1\n3\n5\n", ss.str());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestContinuousNumber) {
    try {
		gp2::CompLine a;
		a.addPLine(3);
		a.addPLinePoint(0,0);
		a.addPLinePoint(2,0);
		a.addPLinePoint(2,1);
		a.addPLinePoint(4,1);
		a.addPLinePoint(4,0);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_SUITE_END()
