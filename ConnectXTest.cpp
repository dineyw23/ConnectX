/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
const Piece ConnectX::BLACK;
const Piece ConnectX::WHITE;

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
// Keeping the sanity check for reference
TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//Test to check if the default turn is set to BLACK.
TEST(ConnectXTest,defaultwhoseTurn)
{
  ConnectX connectXObj;
  ASSERT_EQ(ConnectX::BLACK,connectXObj.whoseTurn());
}


