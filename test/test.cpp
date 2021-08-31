/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file     hw01-test.cpp
 * @authors  Jim Daehn <jdaehn@missouristate.edu>
 * @brief    HW01 Unit test implementation -- DO NOT MODIFY THIS FILE!!!
 */

#define CATCH_CONFIG_MAIN  // Tell Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "csc232.h"

#if PART_1_COMPLETE
SCENARIO( "Part 1", "[part1]")
{
    const char original[] = "ABC123";

    // This can be an ofstream as well or any other ostream
    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf *sbuf = std::cout.rdbuf();
    // Redirect cout to our stringstream buffer or any other ostream
    std::cout.rdbuf(buffer.rdbuf());
    int first;
    int last;

    GIVEN( "An empty string" )
    {
        first = 0;
        last = -1;
        REQUIRE( last - first < 0);

        WHEN( "we write it backwards" )
        {
            csc232::writeArrayBackward(original, first, last);

            THEN( "it is still empty" )
            {
                REQUIRE(buffer.str().size() == 0);
                std::cout.rdbuf(sbuf);
            }
        }
    }

    GIVEN( "A string of length 1" )
    {
        first = 0;
        last = 0;
        REQUIRE( last - first >= 0);

        WHEN( "we write it backwards" )
        {
            csc232::writeArrayBackward(original, first, last);

            THEN( "it is same string" )
            {
                REQUIRE(buffer.str() == "A");
                std::cout.rdbuf(sbuf);
            }
        }
    }

    GIVEN( "A string of even length" )
    {
        first = 0;
        last = 1;
        REQUIRE( (last - first + 1) % 2 == 0);

        WHEN( "we write it backwards" )
        {
            csc232::writeArrayBackward(original, first, last);
            THEN( "the same even number of characters are reversed" )
            {
                REQUIRE(buffer.str() == "BA");
                std::cout.rdbuf(sbuf);
            }
        }
    }

    GIVEN( "A string of odd length" )
    {
        first = 0;
        last = 2;
        REQUIRE( (last - first + 1) % 2 == 1);

        WHEN( "we write it backwards" )
        {
            csc232::writeArrayBackward(original, 0, 2);

            THEN( "the same odd number of characters are reversed" )
            {
                REQUIRE(buffer.str() == "CBA");
                std::cout.rdbuf(sbuf);
            }
        }
    }
}
#endif 

#if PART_2_COMPLETE
SCENARIO( "Part 2", "[part2]" )
{
    const double data[] = {1.0, 2.0, 3.0, 2.0, 1.0};
    int n;
    double result;

    GIVEN( "An array of at least size 1" )
    {
        n = 1;

        WHEN( "We compute the product of the first element" )
        {
            result = csc232::computeProduct(data, n);

            THEN( "it is the value of the one element" )
            {
                REQUIRE(result == Approx(1.0));
            }
        }
    }

    GIVEN( "An array of at least size 2" )
    {
        n = 1;

        WHEN( "We compute the product of the first element" )
        {
            result = csc232::computeProduct(data, n);

            THEN( "it is the value of the first element" )
            {
                REQUIRE(result == Approx(1.0));
            }
        }
    }

    GIVEN( "An array of at least size 2" )
    {
        n = 2; 

        WHEN( "We compute the product of the two elements" )
        {
            result = csc232::computeProduct(data, n);

            THEN( "it is the value of the first element times the second element" )
            {
                REQUIRE(result == Approx(2.0));
            }
        }
    }

    GIVEN( "An array of at least size 3" )
    {
        n = 3;

        WHEN( "We compute the product of the first three elements" )
        {
            result = csc232::computeProduct(data, n);

            THEN( "it is the value of the product of all the elements" )
            {
                REQUIRE(result == Approx(6.0));
            }
        }
    }
}
#endif

#if PART_3_COMPLETE
SCENARIO( "Part 3", "[part3]" )
{
    const double data[] = {1.0, 2.0, 3.0, 2.0, 1.0};
    int first;
    int last;
    double result;

    GIVEN( "An sub-array of the first element" )
    {
        first = 0;
        last = 0;

        WHEN( "We compute the product of the first element" )
        {
            result = csc232::computeProduct(data, first, last);

            THEN( "it is the value of the one element" )
            {
                REQUIRE(result == Approx(1.0));
            }
        }
    }

    GIVEN( "An sub-array of the second element" )
    {
        first = 1;
        last = 1;

        WHEN( "We compute the product of the first element" )
        {
            result = csc232::computeProduct(data, first, last);

            THEN( "it is the value of the one element" )
            {
                REQUIRE(result == Approx(2.0));
            }
        }
    }

    GIVEN( "An sub-array of the third element" )
    {
        first = 2;
        last = 2;

        WHEN( "We compute the product of the first element" )
        {
            result = csc232::computeProduct(data, first, last);

            THEN( "it is the value of the one element" )
            {
                REQUIRE(result == Approx(3.0));
            }
        }
    }

    GIVEN( "An array of at least size 3" )
    {
        first = 1;
        last = 3;

        WHEN( "We compute the product of the first three elements" )
        {
            result = csc232::computeProduct(data, first, last);

            THEN( "it is the value of the product of all the elements" )
            {
                REQUIRE(result == Approx(12.0));
            }
        }
    }
}
#endif
