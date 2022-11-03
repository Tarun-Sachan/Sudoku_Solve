#include <iostream>
#define N 9
using namespace std;
/*
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
*/
bool isPresentInCol(int col, int num,int grid[9][9]){ //check whether num is present in col or not
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInRow(int row, int num,int grid[9][9]){ //check whether num is present in row or not
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num,int grid[9][9]){
//check whether num is present in 3x3 box or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(int grid[9][9]){ //print the sudoku grid after solve
   
   cout<<"\n\n----------------------------------------\n\n";
   cout<<"        SUDOKU SOLUTION\n\n";
   cout<<"----------------------------------------\n\n\n";
   
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout <<"\n";
   }
   cout<<"\n\n\n";
}
bool findEmptyPlace(int &row, int &col,int grid[9][9]){ //get empty location and update row and column
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}
bool isValidPlace(int row, int col, int num,int grid[9][9]){
   //when item not found in col, row and current 3x3 box
   return !isPresentInRow(row, num,grid) && !isPresentInCol(col, num,grid) && !isPresentInBox(row - row%3 ,col - col%3, num,grid);
}
bool solveSudoku(int grid[9][9]){
   int row, col;
   if (!findEmptyPlace(row, col,grid))
      return true; //when all places are filled
   for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
      if (isValidPlace(row, col, num,grid)){ //check validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku(grid)) //recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}
void display(){
    cout<<"----------------------------------------\n";
    cout<<"----------------------------------------\n";
    cout<<"\t      SUDOKU SOLVER\n";
    cout<<"---------------------------------------\n";
    cout<<"----------------------------------------\n";
    cout<<"\n           INSERT SUDOKU VALUES\n ";
    cout<<"\n       NOTE-> For empty cell insert 0\n";
    cout<<"\n----------------------------------------\n";
}
int main(){

    int grid[9][9];
    display();
    cout<<"\n\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
   if (solveSudoku(grid) == true)
      sudokuGrid(grid);
   else
      cout << "No solution exists";
}