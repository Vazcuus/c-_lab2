#define BOOST_TEST_MODULE test_version

#include "lib.h"
#include "lab2.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(LexiSort(19, 12) > 0);
    BOOST_CHECK(LexiSort(20, 23) > 0);
    BOOST_CHECK(LexiSort(55, 52) > 0);
}

BOOST_AUTO_TEST_SUITE_END()
