#include<bits/stdc++.h>
using namespace std ;

void Knapsack(vector<int> profit, vector<int> weight, int n, int M) {
    vector<vector<int>> dp(n, vector<int>(M + 1, 0));

    for (int i = weight[0]; i <= M; i++) {
        dp[0][i] = profit[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= M; j++) {
     
            int notTake = dp[i - 1][j];
            int take = INT_MIN;  
            
            if (weight[i] <= j) {
                take = profit[i] + dp[i - 1][j - weight[i]];
            }
        
            dp[i][j] = max(take, notTake);
        }
    }

    // The answer will be stored in dp[n-1][M]
    cout << "\nMaximum Profit --> " << dp[n - 1][M] << endl;
}
int main (){
    int n , M ;
    cout << "Enter Number of element : ";
    cin >> n ;
    vector<int> profit(n , 0);
    vector<int> weight(n , 0);
    cout << "Enter profit , weight : ";
    for (int i = 0 ; i < n ; i++) {
        int p , w;
        cin >> p >> w;
        profit[i] = p;
        weight[i] = w;
    }
    cout << "Enter Knapsack Capacity : ";
    cin >> M;

    Knapsack(profit , weight, n , M);
}
