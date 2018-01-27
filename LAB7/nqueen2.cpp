#include<iostream>
using namespace std;

void board_initialize(int board[][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
}

void display_board(int board[][8])
{
   int i,j;
   for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
           cout<<board[i][j]<<" ";
      }
      cout<<endl;
   }
}


int place_available(int board[][8], int row, int col)
{
   int i, j;

   for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return 0;
        }
    }
   i = row;
   j = col;
   while (i >= 0 && j >= 0)
    {
      if (board[i][j] == 1)
        {
            return 0;
        }
      i--;
      j--;
    }
   i = row;
   j = col;
   while (i < 8 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int PlaceQueen(int board[][8], int col)
{
   if (col >= 8)
    {
        return 1;
    }

   int i;
   for (i = 0; i < 8; i++)
    {
        if (place_available(board, i, col))
        {
            board[i][col] = 1;
            if (PlaceQueen(board, col + 1) == 1)
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

int main()
{
   int board[8][8];
   board_initialize(board);
   int solution = PlaceQueen(board,0);
   if (solution)
    {
        cout<<"The chessboard is: "<<endl;
        display_board(board);
    }
   else
   {
        cout<<"Solution isn't possible"<<endl;
   }
   return 0;
}
