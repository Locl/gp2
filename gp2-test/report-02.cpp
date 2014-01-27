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


BOOST_AUTO_TEST_CASE(TestValidCase2) {
	try {
		gp2::CompLine a;
		std::vector<int> matchlist;
		std::stringstream ss;
		a.addPLine(4);
		a.addPLinePoint(-60,-75);
		a.addPLinePoint(-60,-78);
		a.addPLinePoint(-42,-78);
		a.addPLinePoint(-42,-6);
		a.addPLine(4);
		a.addPLinePoint(10,3);
		a.addPLinePoint(10,7);
		a.addPLinePoint(-4,7);
		a.addPLinePoint(-4,40);
		a.addPLine(4);
		a.addPLinePoint(-74,66);
		a.addPLinePoint(-74,63);
		a.addPLinePoint(-92,63);
		a.addPLinePoint(-92,135);
		a.addPLine(4);
		a.addPLinePoint(-12,22);
		a.addPLinePoint(-12,25);
		a.addPLinePoint(-30,25);
		a.addPLinePoint(-30,-47);
		a.addPLine(4);
		a.addPLinePoint(12,-22);
		a.addPLinePoint(12,-25);
		a.addPLinePoint(30,-25);
		a.addPLinePoint(30,47);
		matchlist = a.comparePLine();
		for(std::vector<int>::iterator it = matchlist.begin(); it != matchlist.end(); it++){
			ss << *it << "\n";
		}
		BOOST_CHECK_EQUAL("3\n4\n", ss.str());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase3) {
	try {
		gp2::CompLine a;
		std::vector<int> matchlist;
		std::stringstream ss;
		a.addPLine(5);
		a.addPLinePoint(-8,5);
		a.addPLinePoint(-8,2);
		a.addPLinePoint(0,2);
		a.addPLinePoint(0,4);
		a.addPLinePoint(8,4);
		a.addPLine(5);
		a.addPLinePoint(-3,-1);
		a.addPLinePoint(0,-1);
		a.addPLinePoint(0,7);
		a.addPLinePoint(-2,7);
		a.addPLinePoint(-2,16);
		a.addPLine(5);
		a.addPLinePoint(-1,6);
		a.addPLinePoint(-1,3);
		a.addPLinePoint(7,3);
		a.addPLinePoint(7,5);
		a.addPLinePoint(16,5);
		a.addPLine(5);
		a.addPLinePoint(0,1);
		a.addPLinePoint(0,-2);
		a.addPLinePoint(8,-2);
		a.addPLinePoint(8,0);
		a.addPLinePoint(17,0);
		matchlist = a.comparePLine();
		for(std::vector<int>::iterator it = matchlist.begin(); it != matchlist.end(); it++){
			ss << *it << "\n";
		}
		BOOST_CHECK_EQUAL("", ss.str());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase4) {
    try {
		gp2::CompLine a;
		std::vector<int> matchlist;
		std::stringstream ss;
		std::stringstream ss2;
		for(int i = 0; i < 51; i++){
			a.addPLine(10);
			a.addPLinePoint(0,0);
			a.addPLinePoint(9999,0);
			a.addPLinePoint(9999,-9999);
			a.addPLinePoint(-9999,-9999);
			a.addPLinePoint(-9999,9999);
			a.addPLinePoint(9999,9999);
			a.addPLinePoint(9999,100);
			a.addPLinePoint(0,100);
			a.addPLinePoint(0,-9999);
			a.addPLinePoint(-100,-9999);
		}
		matchlist = a.comparePLine();
		for(std::vector<int>::iterator it = matchlist.begin(); it != matchlist.end(); it++){
			ss << *it << "\n";
		}
		for(int i = 1; i < 51; i++){
			ss2 << i << "\n";
		}
		BOOST_CHECK_EQUAL(ss2.str(), ss.str());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestTooManyPoint) {
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

BOOST_AUTO_TEST_CASE(TestNoExistPLine) {
    try {
		gp2::CompLine a;
		a.addPLinePoint(0,0);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestFewPLine) {
    try {
		gp2::CompLine a;
		std::vector<int> matchlist;
		a.addPLine(3);
		a.addPLinePoint(0,0);
		a.addPLinePoint(0,3);
		a.addPLinePoint(2,3);
		matchlist = a.comparePLine();
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestManyPLine) {
    try {
		gp2::CompLine a;
		std::vector<int> matchlist;
		for(int i = 0; i < 52; i++){
			a.addPLine(3);
			a.addPLinePoint(0,0);
			a.addPLinePoint(0,3);
			a.addPLinePoint(2,3);
		}
		matchlist = a.comparePLine();
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooManyPointNum) {
    try {
		gp2::CompLine a;
		a.addPLine(11);
		a.addPLinePoint(0,0);
		a.addPLinePoint(2,0);
		a.addPLinePoint(2,1);
		a.addPLinePoint(4,1);
		a.addPLinePoint(4,0);
		a.addPLinePoint(6,0);
		a.addPLinePoint(6,-2);
		a.addPLinePoint(5,-2);
		a.addPLinePoint(5,-8);
		a.addPLinePoint(3,-8);
		a.addPLinePoint(3,-4);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooFewPointNum) {
    try {
		gp2::CompLine a;
		a.addPLine(2);
		a.addPLinePoint(0,0);
		a.addPLinePoint(2,0);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooHighPointX) {
    try {
		gp2::CompLine a;
		a.addPLine(3);
		a.addPLinePoint(0,0);
		a.addPLinePoint(10000,0);
		a.addPLinePoint(10000,100);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooLowPointX) {
    try {
		gp2::CompLine a;
		a.addPLine(3);
		a.addPLinePoint(0,0);
		a.addPLinePoint(-10000,0);
		a.addPLinePoint(-10000,100);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooHighPointY) {
    try {
		gp2::CompLine a;
		a.addPLine(3);
		a.addPLinePoint(0,0);
		a.addPLinePoint(200,0);
		a.addPLinePoint(200,10000);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooLowPointY) {
    try {
		gp2::CompLine a;
		a.addPLine(3);
		a.addPLinePoint(0,0);
		a.addPLinePoint(200,0);
		a.addPLinePoint(200,-10000);
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_SUITE_END()
