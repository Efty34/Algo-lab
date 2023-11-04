#include <bits/stdc++.h>
using namespace std;

const int N=8;
int countsol=0;

bool isSafe(vector<vector<bool>>& board,int row,int col)
{
    for(int i=0;i<col;i++) {
        if(board[row][i])
            return false;
    }

    for(int i=row,j=col; i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }

    for(int i=row, j=col; i<N && j>=0; i++,j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

void placeQueens(vector<vector<bool>>& board,int col,int k)
{
    if (col==N)
    {
        if (k==0)
        {
            countsol++;
        }
        return;
    }

    for(int row=0;row<N;row++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]=true;
            placeQueens(board,col+1,k-1);
            board[row][col]=false;
        }
    }
    placeQueens(board,col+1,k);
}

int countkqueen(int k)
{
    vector<vector<bool>>board(N,vector<bool>(N,false));
    countsol = 0;
    placeQueens(board,0,k);
    return countsol;
}


int main()
{
    int k;
    cin>>k;

    int sol=countkqueen(k);

    cout<<k<<" queen "<<"can be place "<<sol<<" ways"<<endl;

    return 0;
}


