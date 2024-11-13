#include<bits/stdc++.h>
using namespace std;
class Item {
    public :
    int weight ;
    int profit ;
   
};

static bool cmp (pair<double , Item> a , pair<double , Item> b) {
    return a.first > b.first;
}

void fractional_knapsapk(Item arr[] , int n , int M){
    vector<pair<double , Item>> temp;
    for (int i = 0 ; i < n ; i++){
        double Fraction = (1.0 * arr[i].profit) / (arr[i].weight);
        temp.push_back({Fraction,arr[i]});
    }

    sort(temp.begin(),temp.end(),cmp);

    int MaxProfit = 0 ;
    for (int i = 0 ; i < n; i++){
        if (temp[i].second.weight > M){
            MaxProfit += M * temp[i].first;
            break;
        }else {
            MaxProfit += temp[i].second.profit;
            M -= temp[i].second.weight;
        }
    }
    cout << "\nMaximun Profit --> " << MaxProfit << endl ;
}
int main (){
    int n , M ;
    cout << "Enter Number of element : ";
    cin >> n ;
    Item arr[n];
    cout << "Enter profit , weight : ";
    for (int i = 0 ; i < n ; i++) {
        int p , w;
        cin >> p >> w;
        arr[i].profit = p;
        arr[i].weight = w;
    }
    cout << "Enter Knapsack Capacity : ";
    cin >> M;

    fractional_knapsapk(arr , n , M);
}

/*
OUTPUT ::

Enter Number of element : 5
Enter profit , weight : 10 3
10 2
15 3
20 5
8 1
Enter Knapsack Capacity : 10

Maximun Profit --> 49
*/