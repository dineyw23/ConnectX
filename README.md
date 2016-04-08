## Bug Report By **Diney Wankhede**

#### BUG 1: inBounds function returns TRUE if Width is Invalid and Height is valid. This affects the behavior of `at` function.

  
  * Issue Description:
  The `inBounds` function should return FALSE if either Height or Width is invalid.
  The first if condition checks whether the Width is valid or not. If the width is
  invalid it sets 'inside' variable to FALSE, which is correct behavior.
  The second if condition checks whether the Height is valid or not. If the height 
  is invalid it sets the same variable (inside) to TRUE.
  The return statement should return FALSE.
  
  * Steps to replicate:
  - Create default size game board.
  - Call at function with 100 as first parameter and 3 as second parameter.
  - Check Test - `atInvalidWidthOnly`.

  * Observed Behavior:
    The function returns TRUE if Width is invalid and Height is valid.
  
  * Expected Behavior:
    The function should return FALSE if Width is invalid and Height is valid as it is not in Bounds of the gameboard.

  * One of the ideas to fix the bug.

```C++ 
bool ConnectX::inBounds(int w, int h)
{ 
	bool inside;
	if( w>=width || w<0 )
  {
		inside = false;
	  return inside;
  }
  else
		inside = true;

	if( h<0 || h>=height )
		inside = false;
	else
		inside = true;

	return inside;
}
```


#### BUG 2: `placePiece` function places a piece on board even tough invalid column is passed 
  * Issue Description
  The `placePiece` function should JUST toggle turns if invalid position is passed as an argument.
  placePiece should not place any Piece on board if invalid column id specified, it should just toggle turn.
  The placePiece function toggles turn but also places a `BLACK` piece on the board if random large value is passed.
  The `inBound` function returns true and also vector resizes. If `signed int` (negative) is passed to vector, it implicitly typecasts it to `unsigned int`.
  This results in `placePiece` putting a piece on board randomly. The ideal behavior should just toggle turn.

  * Steps to replicate
    - Call `placePiece` with `-10` as argument. 
    - Check the board, there should not be any piece on the board.

  * Example: Test `placePieceRandom` will fail and expose this bug.    
