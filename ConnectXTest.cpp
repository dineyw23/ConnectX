/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
const Piece ConnectX::BLACK;
const Piece ConnectX::WHITE;
const Piece ConnectX::INVALID;
const Piece ConnectX::EMPTY;

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

TEST(ConnectXTest,atInvalidWidthandHeight)
{
  //Assures that we are explicitly specifying the size of board.
  ConnectX connectXObj(5,5,3);
  ASSERT_EQ(ConnectX :: INVALID,connectXObj.at(6,6));
}


//This test has only the width INVALID but it should return INVALID.
//This test exposes BUG1 in the inBounds. It should return INVALID but return garbage
//Even if the width is invalid and height is valid, inBounds will return TRUE.
TEST(ConnectXTest,atInvalidWidthOnly)
{
  ConnectX connectXObj(5,2,3);
  ASSERT_EQ(ConnectX::INVALID,connectXObj.at(10,0));
}

//This checks for height invalid and width valid. 
TEST(ConnectXTest,atInvalidHeightOnly)
{
  ConnectX connectXObj(5,3,3);
  ASSERT_EQ(ConnectX :: INVALID, connectXObj.at(0,4));

}

//This test has only the width INVALID but it should return INVALID.
//This test exposes BUG1 in the inBounds. It should return INVALID but return garbage
//Even if the width is invalid and height is valid, inBounds will return TRUE.
TEST(ConnectXTest,atInvalidWidthLowerBound)
{
  ConnectX connectXObj(5,2,3);
  ASSERT_EQ(ConnectX::INVALID,connectXObj.at(-1,0));
}

//This checks for height invalid and width valid. 
TEST(ConnectXTest,atInvalidHeightLowerLimit)
{
  ConnectX connectXObj(5,3,3);
  ASSERT_EQ(ConnectX::INVALID,connectXObj.at(0,-4));
}

//Place piece in valid column
TEST(ConnectXTest, placePieceValid)
{
  ConnectX connectXObj(4,4,3);
  connectXObj.placePiece(0);
  ASSERT_EQ(ConnectX::WHITE,connectXObj.whoseTurn()); 
  ASSERT_EQ(ConnectX::BLACK,connectXObj.at(0,3));
}

//Place piece in invalid column
TEST(ConnectXTest, placeMineInvalid)
{
  ConnectX connectXObj(4,4,3);
  connectXObj.placePiece(5);//Invalid column
  ASSERT_EQ(ConnectX::WHITE,connectXObj.whoseTurn());

}

//Place pieces more than the height
TEST(ConnectXTest, placePieceColumnOverflow)
{
  ConnectX connectXObj(3,3,2);
  connectXObj.placePiece(0);
  connectXObj.placePiece(0);
  connectXObj.placePiece(0);
  connectXObj.placePiece(0);
  ASSERT_EQ(ConnectX::BLACK,connectXObj.whoseTurn());
  ASSERT_EQ(ConnectX::BLACK,connectXObj.at(0,2));
}


//Test for constructor
TEST(ConnectXTest,cstrWidthZero)
{
  ConnectX connectXObj(0,5,2);
  ASSERT_EQ(ConnectX :: EMPTY,connectXObj.at(1,1));
}

//Test for constructor
TEST(ConnectXTest,cstrHeightZero)
{
  ConnectX connectXObj(5,0,2);
  ASSERT_EQ(ConnectX :: EMPTY,connectXObj.at(1,1)); 
  connectXObj.placePiece(0);
  connectXObj.placePiece(0);
  connectXObj.showBoard();//Just called for sanity check and coverage.
}

//Test for constructor
TEST(ConnectXTest,cstrToWinZero)
{
  ConnectX connectXObj(5,2,0);
  connectXObj.placePiece(0);
  ASSERT_EQ(ConnectX :: BLACK,connectXObj.at(0,5));
  
} 

//Test to expose BUG2. places a piece randomly on the board. 
TEST(ConnectXTest,placePieceRandom)
{
  bool check = false;
  ConnectX connectXObj;
  connectXObj.placePiece(-10);
  connectXObj.showBoard();
  for(int i = 0; i < 7;++i)
  {
    for(int j = 0; j < 6; ++j)
      if(ConnectX::EMPTY != connectXObj.at(i,j))
        check = true;
  }
  ASSERT_EQ(check,false); 
} 

