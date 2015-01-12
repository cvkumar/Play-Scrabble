
/*
  pre-conditions of entire program
  num_rows is a real integer
  num_cols is a real integer
  command any string is typed in for it
  post-conditions
(~ Courtesy of Professor Walker)

  If the user enters a word, followed by a space and the letter R, then the 
  program is free to place the word any place at random where the word fits.
  If the user enters a word, followed by a space, the letter H, a space, a 
  number i, a space, and another number j, then the word is to be placed 
  horizontally with the first letter at row i and column j.
  If the user enters a word, followed by a space, the letter V, a space, 
  a number i, a space, and another number j, then the word is to be placed 
  vertically with the first letter at the row i and column j. 

  If the word placement is given and is valid, the word is added to the grid, 
  and the grid is printed. (I.e., the word is added if it intersects with 
  at least one letter already on the board, and the letters match each 
  time the new word intersects an existing one letter in the grid).
  If the word placement is not given (letter R is entered), then the word 
  is added to the grid once at any valid position (if such a position 
  exists), and the grid is printed.
  If the word cannot be added at the specified location or if no position 
  is possible for an open placement, then an error message is printed.
  The program continues to ask the user to enter words until the user 
  enters QUITQUIT, in which case the program stops.
*/





#include <stdio.h>
#include <string.h>


/*
  pre-conditions of gridempty
  num_rows is the total number of rows in the grid
  num_cols is the total number of columns in the grid
  grid is the two-dimensional array representing the grid
  post-conditions
  returns true (i.e., 1) if given grid only contains spaces (' ')
  returns false (i.e., 0) otherwise
*/

int gridempty (int num_rows, int num_columns, char grid[][num_columns])
{
  // declarations for loops
  int k, l;
  //If any locations on the grid are not empty then return false otherwise
  // return true
  for (k = 0; k < num_rows; k++)
    {
      for (l = 0; l < num_columns; l++)
        {
          if (grid[k][l] != ' ')
            {
              return 0; //return false
            }        
        } //end first loop
    } // end second loop
  return 1; // return true
}


/*
pre-conditions
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
   post-conditions
      prints the 2-D array in scrabbleboard form
*/

void printgrid (int num_rows, int num_columns, char grid[][num_columns])
{ 
  //declarations for loops
  int k, l;
 printf ("The ScrabbleBoard\n");
 //print every locations of the board in proper double loop
 for (k = 0; k < num_rows; k++)
   {
     for (l = 0; l < num_columns; l++)
       {
         printf ("%c", grid[k][l]);
       }
     printf ("\n");
   }
} //end of function

/*
pre-conditions
      row is a valid row location within the grid
      col is a valid column location within the grid
      word is a valid string
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
   post-conditions
      returns true (i.e., 1) if the word can be added to the grid
              horizontally with the first letter at the given row and col
      returns false (i.e., 0) otherwise
*/

int check_horizontal (char * word, int row, int col, 
                      int num_rows, int num_cols, char grid[num_rows][num_cols])
{
  int i, j, k;
  i = 0;
  //If grid has words in it then check if any of the letters
  //of given word match with board then store value of i
  //and continue
  if (gridempty(num_rows, num_cols, grid) == 0)
    {
      while (i < strlen(word))
        {
          if (word[i] == grid[row][col] && grid[row][col + 1] == ' ')
            {
              break;
            }
          else
            {
              i++;
            }
        }
    }

 //If none of the letters of word matched with the scrabbleboard return false
  if (i == strlen(word))
   {
     return 0;
   }


  //if word does not fit on board then return false
  if (col - i < 0 || col + strlen(word) - i > num_cols)
    {
      return 0;
    }

  // Check if whole word will fit amoung spaces and other words on board.
  // If it does not return false.
for (i = col - i; i < strlen(word); i++)
        {
        if (word[i] == grid[row][col + i] || grid[row]
            [col + i] == ' ')
          {
          }
          
  else
    {
      return 0;
    }
        }
//every condition has been checked for, thus return true
      return 1;
} // end of function


/*
pre-conditions
      row is a valid row location within the grid
      col is a valid column location within the grid
      word is a valid string
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
   post-conditions
      returns true (i.e., 1) if the word can be added to the grid
              vertically with the first letter at the given row and col
      returns false (i.e., 0) otherwise
*/

//Same style as check_horizontal except with adjusting row (to check vertically)
//instead of adjusting column
int check_vertical (char * word, int row, int col, 
                      int num_rows, int num_cols, char grid[num_rows][num_cols])
{
  //declarations
int i, j, k;
  i = 0;

if (gridempty(num_rows, num_cols, grid) == 0)
    {
      while (i < strlen(word))
        {
          if (word[i] == grid[row][col] && grid[row + 1][col] == ' ')
            {
              break;
            }
          else
            {
              i++;
            }
        }
    }


 if (i == strlen(word))
   {
     return 0;
   }

 if (row - i < 0 || row + strlen(word) - i > num_rows)
   {
     return 0;
   }


 for (i = col - i; i < strlen(word); i++)
   {
     if (word[i] == grid[row + i][col] || grid[row + i]
         [col] == ' ')
       {
       }
          
     else
       {
         return 0;
       }
   }
 return 1; // all conditions accounted for, thus return true
} // end of function




void insert_horz (int num_rows, int num_columns, char grid[][num_columns], 
                  int rows, int columns, char word[])
{ 
  int  i, k; // declarations for loops
  i = 0;

  // Find the location of the letter that matched on the board
  while (i < strlen(word))
    {
      if (word[i] == grid[rows][columns])
        {
          break;
        }
      else
        {
          i++;
        }
    }

  // Based on where the initial letter of the word matched, place the word
  for (k = 0; k < strlen(word); k++)
    {
      grid [rows][columns - i + k] = word[k];
    }  
} //end of function
       

//same as insert_horz except adjusting row to place word horizontally
void insert_vert (int num_rows, int num_columns, char grid[][num_columns], 
                  int rows, int columns, char word[])
{ 
  //declarations for loops
  int i, k;
  i = 0;

  if (gridempty(num_rows, num_columns, grid) == 0)
    {
      while (i < strlen(word))
        {
          if (word[i] == grid[rows][columns])
            {
              break;
            }
          else
            {
              i++;
            }
        }
    }

 printf ("%d = i \n", i);

  for (k = 0; k < strlen(word); k++)
    {
      grid [rows - i + k][columns] = word[k];
    }
} // end of function 


void random (int num_rows, int num_columns, char grid[][num_columns],
             char word[])
{
  //declarations for loops
  int k, j;

  // Check if any locations on board allow for placement of given word
  // If it does, then place the word and end the loops
  for (j = 0; j < num_rows - strlen(word); j++) // Check until end of board
    {
      for (k = 0; k < num_columns - strlen(word); k++)//Check until end of board
        {
          if  (check_horizontal (word, j, k, num_rows, num_columns, grid))
            {
              insert_horz (num_rows, num_columns, grid, j, k, word);
              //change values of k and j to end loops
              k = num_columns; 
              j = num_rows;
            }
          else if  (check_vertical (word, j, k, num_rows, num_columns, grid))
            {
              insert_vert (num_rows, num_columns, grid, j, k, word);
              //change values of k and j to end loops
              k = num_columns;
              j = num_rows;
            }
        }
    }
  if (j == num_rows - strlen(word) || k == num_columns - strlen(word))
    {
      printf ("no places available\n");
    }
} // end of function


int main()
{
  //declarations
  //k, l, m: used for loops
  //num_rows and num_columns: height and width of scrabbleboard
  // counter used for random function in loop
  // command used for while loop
  int rows, columns, k, l, m; 
  int num_rows, num_columns;
  int counter = 0;
  char command;

  printf ("how many rows do you want?\n"); //rows of board and store it
  scanf ("%d", &num_rows);

  printf ("how many columns do you want?\n"); //columns of board and store it
  scanf ("%d", &num_columns);

  // make sure input large enough for any word
  char input[num_rows + num_columns];

  //set up scrabbleboard
  char scrabbleboard [num_rows][num_columns];

  //All elements of board set to 0
  for (k = 0; k < num_rows; k++)
    {
      for (l = 0; l < num_columns; l++)
        {
          scrabbleboard[k][l] = ' ';
        }
    }

  m = 1; //set m to one to allow while loop to run until break statement used

  while (m)
    {
      //Options
      printf ("Scrabble Options\n"); 
      printf ("what word would you like to place on the board and where?\n");
      printf ("to horizontally place: word H row column\n");
      printf ("to vertically place: word V row column\n");
      printf ("to randomly place: word R\n");
      printf ("to Quit: QUITQUIT\n");
      printf ("note to user: will run random if command unrecognized\n");

      scanf ("%s", &input);

      if (strcmp (input, "QUITQUIT") == 0) // stop function if QUITQUIT is input
        {
          break; //break loop
        }
      else
        {
          scanf (" %c", &command); //obtain command after space
        }

      if (command == 'R') //if command was R, run random function
        {          
          printf("random insertion\n");
          random (num_rows, num_columns, scrabbleboard, input);
          printgrid (num_rows, num_columns, scrabbleboard);
          counter = 1; //add 1 to counter
        }
      //if command was not R then obtain values of rows and columns
      else 
        {
          scanf (" %d %d",  &rows, &columns);
        }

      //If command was H check if the locations works and then place the input
      // horizontally otherwise print error
      if (command == 'H')
        {
          printf("horizontal insert\n");
          if (check_horizontal (input, rows, columns, num_rows, num_columns, 
                                scrabbleboard))
            {
              insert_horz (num_rows, num_columns, scrabbleboard, rows, 
                           columns, input);
              printgrid (num_rows, num_columns, scrabbleboard);
            }
          else
            {
              printf ("error: Given word cannot fit on board\n");
            }
        }
      //If command was V check if the locations works and then place the input
      //vertically otherwise print error
      else if (command == 'V')
        {
          printf("vertical insert\n");
          if (check_vertical (input, rows, columns, num_rows, num_columns, 
                              scrabbleboard))
            {
              insert_vert (num_rows, num_columns, scrabbleboard, rows, 
                           columns, input);
              printgrid (num_rows, num_columns, scrabbleboard);       
            }
          else 
            {
              printf ("error, Given word cannot fit on board\n");
            }
        }
      //If previous random function not run, then run random function because
      //the command did not match with anything else
      else if (counter == 0)
        { 
          printf("random insertion\n");
          random (num_rows, num_columns, scrabbleboard, input);
          printgrid (num_rows, num_columns, scrabbleboard);
          counter = 0; 
        }
    } //end loop
     
} //end main
