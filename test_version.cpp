#define BOOST_TEST_MODULE test_version

#include "lib.h"
#include "lab2.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    int *arr_test = new int[6]{12, 14, 15, 17, 18, 20};
    BOOST_CHECK(LexiSort(arr_test[0], arr_test[1]) > 0);
    BOOST_CHECK(LexiSort(arr_test[2], arr_test[3]) > 0);
    BOOST_CHECK(LexiSort(arr_test[4], arr_test[5]) > 0);
}

BOOST_AUTO_TEST_SUITE_END()
