#include <boost/test/unit_test.hpp>
#include "../gp2/tileset.h"

BOOST_AUTO_TEST_SUITE(Example3Test)

BOOST_AUTO_TEST_CASE(TestValidCase1) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.calculate();
        BOOST_CHECK_EQUAL(45, room.reachable_count());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase2) {
    try {
        gp2::tileset room(11, 9);
        room.add(".#.........");
        room.add(".#.#######.");
        room.add(".#.#.....#.");
        room.add(".#.#.###.#.");
        room.add(".#.#..@#.#.");
        room.add(".#.#####.#.");
        room.add(".#.......#.");
        room.add(".#########.");
        room.add("...........");
        room.calculate();
        BOOST_CHECK_EQUAL(59, room.reachable_count());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase3) {
    try {
        gp2::tileset room(11, 6);
        room.add("..#..#..#..");
        room.add("..#..#..#..");
        room.add("..#..#..###");
        room.add("..#..#..#@.");
        room.add("..#..#..#..");
        room.add("..#..#..#..");
        room.calculate();
        BOOST_CHECK_EQUAL(6, room.reachable_count());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestValidCase4) {
    try {
        gp2::tileset room(7, 7);
        room.add("..#.#..");
        room.add("..#.#..");
        room.add("###.###");
        room.add("...@...");
        room.add("###.###");
        room.add("..#.#..");
        room.add("..#.#..");
        room.calculate();
        BOOST_CHECK_EQUAL(13, room.reachable_count());
    }
    catch (std::exception& err) {
        BOOST_FAIL(err.what());
    }
}

BOOST_AUTO_TEST_CASE(TestInvalidCharacter) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add("...*.#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.calculate();
        BOOST_FAIL("never reached");
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooMachColumn) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.calculate();
        BOOST_FAIL("never reached");
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooFewColumn) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("..");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.calculate();
        //BOOST_FAIL("never reached");
        BOOST_TEST_PASSPOINT();
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooMachRow) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.add(".#..#.");
        room.add(".#..#.");
        room.add(".#..#.");
        room.add(".#..#.");
        room.calculate();
        BOOST_FAIL("never reached");
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestTooFewRow) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.calculate();
        //BOOST_FAIL("never reached");
        BOOST_TEST_PASSPOINT();
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_CASE(TestMultiplePerson) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#@@@.#");
        room.add(".#..#.");
        room.calculate();
        BOOST_FAIL("never reached");
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
    
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("....@.");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#@...#");
        room.add(".#..#.");
        room.calculate();
        BOOST_FAIL("never reached");
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }

}

BOOST_AUTO_TEST_CASE(TestNoPerson) {
    try {
        gp2::tileset room(6, 9);
        room.add("....#.");
        room.add(".....#");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("......");
        room.add("#....#");
        room.add(".#..#.");
        room.calculate();
        BOOST_FAIL("never reached");
    }
    catch (std::exception& /* err */) {
        BOOST_TEST_PASSPOINT();
    }
}

BOOST_AUTO_TEST_SUITE_END()
