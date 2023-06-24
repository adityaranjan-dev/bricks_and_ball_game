# bricks_and_ball_game
A maze game to find the path from source to destination using the concept of backtracking.

There is a given maze of size M x N. The source and the destination location are 
top-left cell and bottom-right cell respectively. Some cells are valid to move and some cells are 
blocked. If we start moving from the start vertex to the destination vertex, we have to find that is there 
any way to complete the path, if it is possible then mark the correct path for the ball. The maze 
is given using a binary matrix, where it is marked with 1, it is a valid path, otherwise 0 for a 
blocked cell.
The ball can only move in two directions, either to the right or to the down. To solve these types 
of mazes, we first start with the source cell and move in a direction where the path is not blocked. 
If the path taken makes us reach the destination, then the puzzle is solved. Otherwise, we come 
back and change the direction of the path taken.

