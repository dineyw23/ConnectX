## Bug Report By **Diney Wankhede**

#### BUG 1: inBounds function returns TRUE if Width is Invalid and Height is valid.

  
  * Issue Description:
  The inBounds function should return FALSE if either Height or Width is invalid.
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

