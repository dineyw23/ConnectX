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

//This test assures if the whoseTurn return White
TEST(ConnectXTest,whoseTurnAfterOnePlacePiece)
{
  ConnectX connectXObj;
  connectXObj.placePiece(1);
  ASSERT_EQ(ConnectX::WHITE, connectXObj.whoseTurn());
}

//Apart from default, whose turn should return BLACK.
//This test if check if it return BLACK again.
TEST(ConnectXTest,whoseTurnAfterTwoPlacePiece)
{
  ConnectX connectXObj;
  connectXObj.placePiece(1);
  connectXObj.placePiece(2);
  ASSERT_EQ(ConnectX::BLACK, connectXObj.whoseTurn());
}

