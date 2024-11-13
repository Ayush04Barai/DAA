#include<bits/stdc++.h>
using namespace std ;
void addList(vector<vector<int>> &board , vector<vector<int>> &ans , int n){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ;j < n ; j++) ans[i][j]=board[i][j];
    }
}
bool isSafe (vector<vector<int>> &board , int n , int col , int row ){
    int x = row;
    int y = col;
    while (y >= 0){
        if (board[x][y]==1) return false ;
        y--;
    }
     x = row;
     y = col;
    while (y >= 0 && x >= 0){
        if (board[x][y]==1) return false ;
        y--;
    }
     x = row;
     y = col;
    while (y >= 0 && x < n){
        if (board[x][y]==1) return false ;
        y--;
        x++;
    }
    return true;
}
void Nqueen(vector<vector<int>> &board , vector<vector<int>> &ans , int col ,int n ){
    if (col == n) {
        addList(board , ans , n);
        return;
    }

    for (int i = 0 ; i < n ; i++){
        if (isSafe(board , n , col , i )){
            board[i][col]=1;
            Nqueen(board , ans , col+1 , n );
            board[i][col]=0;
        }
    }
}
int main (){
    int n ;
    cout << "Enter No of Queen : ";
    cin >> n;
    vector<vector<int>> ans (n , vector<int>(n,0));
    vector<vector<int>> board (n , vector<int>(n,0));
    Nqueen( board , ans , 0 , n);
    cout << "\t" << n <<" Queen Matrix \n";
    for (auto it : ans ){
        cout << "\t";
        for (auto jt : it){
            cout << jt << " ";
        }
        cout << endl ;
    }
}
/*
OUTPUT :

Enter No of Queen : 4
        0 0 1 0
        1 0 0 0
        0 0 0 1
        0 1 0 0


*/