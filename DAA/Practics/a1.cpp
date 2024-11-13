#include <bits/stdc++.h>
using namespace std;

int BinarySearchRecc(vector<int> arr,int start , int last , int k){
    if (start <= last){
        int mid = (start+last)/2;
        if (arr[mid]==k) return mid ;
        else if (arr[mid] < k) {
            return BinarySearchRecc(arr,mid + 1,last,k) ;
        }else{
            return BinarySearchRecc(arr,start,mid - 1,k) ;
        }
    }
    else return -1;
}

int BinarySearch(vector<int> arr, int n , int k){
    int start = 0 , last = n-1 ;
    while (start <= last){
        int mid = (start+last)/2;
        if (arr[mid]==k) return mid ;
        else if (arr[mid] < k) {
            start = mid + 1 ;
        }else{
            last = mid - 1 ;
        }
    }
    return -1;
}

int main (){
    int k ;
    int n ;
    cout << "Enter No Of element : ";
    cin >> n ;
    vector<int> arr(n , 0);
    cout << "Enter array element : ";
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << " Enter Key to Be search : ";
    cin >> k;
    
    int ind = BinarySearchRecc(arr,0,n-1,k);
    if (ind == -1) cout << "Key is not in array !!" << endl;
    else cout << "Key Present at position " << ind+1 << endl ;
}