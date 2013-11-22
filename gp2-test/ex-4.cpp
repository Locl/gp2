#include <boost/test/unit_test.hpp>
#include "../gp2/mcxi.h"

BOOST_AUTO_TEST_SUITE(Example4Test)

BOOST_AUTO_TEST_CASE(TestValidCase1) {
	try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("xi");
		b.SetMcxi("x9i");
		ans = a + b;
		BOOST_CHECK_EQUAL("3x", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase2) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("i");
		b.SetMcxi("9i");
		ans = a + b;
		BOOST_CHECK_EQUAL("x", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase3) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("c2x2i");
		b.SetMcxi("4c8x8i");
		ans = a + b;
		BOOST_CHECK_EQUAL("6cx", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase4) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("m2ci");
		b.SetMcxi("4m7c9x8i");
		ans = a + b;
		BOOST_CHECK_EQUAL("5m9c9x9i", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase5) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("9c9x9i");
		b.SetMcxi("i");
		ans = a + b;
		BOOST_CHECK_EQUAL("m", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase6) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("i");
		b.SetMcxi("9m9c9x8i");
		ans = a + b;
		BOOST_CHECK_EQUAL("9m9c9x9i", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase7) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("m");
		b.SetMcxi("i");
		ans = a + b;
		BOOST_CHECK_EQUAL("mi", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase8) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("i");
		b.SetMcxi("m");
		ans = a + b;
		BOOST_CHECK_EQUAL("mi", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase9) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("m9i");
		b.SetMcxi("i");
		ans = a + b;
		BOOST_CHECK_EQUAL("mx", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase10) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("9m8c7xi");
		b.SetMcxi("c2x8i");
		ans = a + b;
		BOOST_CHECK_EQUAL("9m9c9x9i", ans.GetMcxi());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestContinuousNumber) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("9m87xi");
		b.SetMcxi("c23x8i");
		ans = a + b;
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestInvalidMCXI) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("9m8xci");
		b.SetMcxi("c2xm8i");
		ans = a + b;
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestInvalidChar) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("u9mxi");
		b.SetMcxi("c2xvi");
		ans = a + b;
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestLastNumber) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("9m8xi9");
		b.SetMcxi("c2x8i2");
		ans = a + b;
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestOutofRange) {
    try {
		gp2::Mcxi a,b,ans;
		a.SetMcxi("9m8c7xi");
		b.SetMcxi("c2x9i");
		ans = a + b;
		ans.GetMcxi();
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestNotSet) {
    try {
		gp2::Mcxi a;
		a.SetMcxi("");
		a.GetMcxi();
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestNotSet2) {
    try {
		gp2::Mcxi a;
		a.GetMcxi();
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestNotSet3) {
    try {
		gp2::Mcxi a,b,ans;
		ans = a + b;
		ans.GetMcxi();
		BOOST_FAIL("never reached");
    }
    catch (std::exception& /*err*/) {
        BOOST_TEST_PASSPOINT();
    }
}


BOOST_AUTO_TEST_SUITE_END()
