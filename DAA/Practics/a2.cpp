#include <bits/stdc++.h>
using namespace std;


int partation (int arr[] , int start ,int end ){
   int i = start , pivot = i , j = end;
   while ( i < j ){
    while (arr[i] < arr[pivot] && i < end) i++;
    while (arr[j] >= arr[pivot] && j > start) j--;
    if (i < j) swap(arr[i],arr[j]);
   }
   swap(arr[j],arr[pivot]);
   return j; 
}
void quicksort(int arr[] , int start , int end ){
    if (start >= end ) return ; 
    int pivotInd = partation(arr , start , end );
    quicksort(arr,start,pivotInd-1);
    quicksort(arr,pivotInd+1,end);
}

int main (){
    int n ;
    cin >> n;
    int arr[n]={0};
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    quicksort(arr,0,n-1);
    for (int it : arr)cout << it << " ";
}

