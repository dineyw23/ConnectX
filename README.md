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

``` bool ConnectX::inBounds(int w, int h)
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


#### BUG 2: Redundant Code in placePiece function

  * Issue Description
  placePiece function has a condition which is redundant. In the `if` statement,first `at` function is called which calls the `inBounds` function and checks if the
  position is valid or not valid. Again the `inBounds` function is called in the second part of the if statement which is not required as we are checking it already using the `at` function. This does not affect the functionality directly but is redundant and it is not possible to cover that particular branch.
