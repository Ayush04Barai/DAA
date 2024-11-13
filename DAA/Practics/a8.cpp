#include<bits/stdc++.h>
using namespace std ;
bool isSafe (int node , vector<vector<int>> G , int color[] , int n , int col){
    for (auto it : G[node]){
        if (color[it]==col) return false ;
    }
    return true ;
}

bool solve (int node ,  vector<vector<int>> G , int color[] , int n , int m){
    if (node == m) return true ;

    for (int i = 1 ; i <= m ; i++){
        if (isSafe(node , G , color , n , i)){
            color[node]=i;
            if (solve(node+1 , G , color , n , m)){
                return true;
            }
            color[node]=0;
        }
    }
}

bool GreaphColor( vector<vector<int>> G , int color[] , int i , int m){
    int n = G.size();
    if (solve(0 , G , color , n , m)) return true ;
    return false ;
}
int main (){
    int v , e , u , w , col;
    cout << "Enter No. of vertices and edges : ";
    cin >> v >> e ;
    vector<vector<int>> G(v);
    for (int i = 0 ; i < e ; i++){
        cout << "Enter Edge from vertex1 to vertex2 : ";
        cin >> u >> w ;
        G[u].push_back(w);
        G[w].push_back(u);
    }
    cout << "Enter No of colors : ";
    cin >> col;
    int color [col]= {0};
    if (GreaphColor(G , color ,0 , v)){

    }
}