#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
};

void selectionSort(Item arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < N; j++) {
            double r1 = (double)arr[maxIndex].value / arr[maxIndex].weight;
            double r2 = (double)arr[j].value / arr[j].weight;
            if (r2 > r1) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

double fractionalKnapsack(int W, Item arr[], int N) {
    
    selectionSort(arr, N);
    
    double totalValue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break; 
        }
    }
    return totalValue;
}

int main() {
    int W = 50; 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int N = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, N);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

