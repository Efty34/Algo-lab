#include<bits/stdc++.h>
using namespace std;

//8-Queen Problem Solution

const int N = 8;

bool board[N][N];

bool isSafe(int row,int col){

    //check rows
    for(int k=0;k<N;k++){
        if(board[row][k]==true) return false;
    }

    //check columns
    for(int k=0;k<8;k++){
        if(board[k][col]==true) return false;
    }

    // check upper diagonal on left

    for(int i=row,j=col;i>=0 and j>=0;i--,j--){
        if(board[i][j]==true) return false;
    }

    // check lower diagonal on left
    for(int i=row,j=col;i<N and j>=0;i++,j--){
        if(board[i][j]==true) return false;
    }
    // all condition satisfied
    return true;
}
int ans;
int k;
bool placeQueen(int col){
    if(col==8){
        if(k==6) ans++;
        return true;
    }
    placeQueen(col+1);
    for(int i=0;i<8;i++){
        if(isSafe(i,col)){
            board[i][col] = true;
            k++;
            placeQueen(col+1);
            k--;
            board[i][col] = false;
        }
    }
    return false;
}
void printQueens(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0) cout<<".";
            else cout<<"Q";
        }
        cout<<endl;
    }
}
int main(){
    placeQueen(0);
    cout<<ans<<endl;
    printQueens();

}
